#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <unordered_map>
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
        cin.get();
        int p = 0;
        int ans = n;
        unordered_map<int,int> mp;
        for(int i=1;i<=2*n;i++)
        {
            char c = cin.get();
            if(c=='(')
            {
                mp[p]++;
                p++;
            }
            else
            {
                if(mp[p]) ans -= mp[p]-1;
                mp[p] = 0;
                p--;
            }
        }
        cout<<ans-mp[0]+1<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
