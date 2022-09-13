#include <iostream>
#include <chrono>
using namespace std;
//==========================================
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
        int n;
        cin>>n;
        string s;
        cin>>s;
        string a;
        for(int i=n-1;i>=0;i--)
        {
            if(i>=2&&s[i]=='0')
            {
                a.push_back(char('a'+(s[i-2]-'0')*10+s[i-1]-'0'-1));
                i -= 2;
            }
            else a.push_back(char('a'+s[i]-'0'-1));
        }
        reverse(a.begin(), a.end());
        cout<<a<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}