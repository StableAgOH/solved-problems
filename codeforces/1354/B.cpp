#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    __red(argc, argv);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.length();
        vector<array<int,3>> lst;
        array<int,3> l = {-1,-1,-1};
        for(int i=0;i<n;i++)
        {
            lst.emplace_back(l);
            l[s[i]-'0'-1] = i;
        }
        int mn = 1e9;
        for(int i=0;i<n;i++)
        {
            int p = 1e9;
            for(int j=0;j<3;j++)
            {
                if(j==s[i]-'0'-1) continue;
                p = min(p, lst[i][j]);
            }
            if(p==-1) continue;
            mn = min(mn, i-p+1);
        }
        cout<<(mn==1e9?0:mn)<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
