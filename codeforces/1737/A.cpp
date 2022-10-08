#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <map>
#include <string>
#include <algorithm>
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        string s;
        cin>>s;
        map<char,int> mp;
        for(auto c : s) mp[c]++;
        int pre = p;
        string r;
        for(char c='a';c<='z';c++)
        {
            if(mp[c]<pre)
            {
                r.insert(r.end(), pre-mp[c], min('a'+n/p, int(c)));
                pre = mp[c];
            }
        }
        sort(r.begin(), r.end(), greater<>());
        cout<<r<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
