#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "debug.hpp"
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
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        vector<array<int,2>> dp(n+1);
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='0') dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            else
            {
                dp[i][0] = dp[i-1][0]+v[i-1];
                dp[i][1] = max(dp[i-1][0],dp[i-1][1])+v[i];
            }
        }
        cout<<max(dp[n][0], dp[n][1])<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
