#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/debug.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        string s,f;
        cin>>s>>f;
        auto n=s.length(), m=f.length();
        s = '$'+s;
        f = '$'+f;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0x3f3f3f3f));
        vector<vector<pair<int,int>>> pre(n+1, vector<pair<int,int>>(m+1));
        for(size_t i=0;i<=n;i++) dp[i][0] = 0;
        for(size_t i=1;i<=n;i++)
        {
            for(size_t j=1;j<=m;j++)
            {
                if(s[i]==f[j])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                    pre[i][j] = {i-1, j-1};
                }
                else
                {
                    dp[i][j] = dp[i-1][j]+1;
                    pre[i][j] = {i-1, j};
                }
            }
        }
        int mn = 0x3f3f3f3f;
        int x=-1;
        for(size_t i=1;i<=n;i++) if(dp[i][m]<mn)
        {
            mn = dp[i][m];
            x = i;
        }
        int y=x, z=m;
        while(pre[y][z].second) tie(y,z) = pre[y][z];
        for(auto i=y;i<=x;i++) cout<<s[i];
        cout<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
