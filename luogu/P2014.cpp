#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
//==========================================
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
#endif
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,W;
    cin>>n>>W;
    vector<int> v(n+1);
    vector<vector<int>> G(n+1);
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        if(p) G[p].push_back(i);
        cin>>v[i];
    }
    int tim = 0;
    vector<int> nfd(n+1), siz(n+1), pre(n+1);
    function<void(int)> dfs = [&](int u)
    {
        nfd[tim++] = u;
        siz[u] = 1;
        for(auto v : G[u])
        {
            pre[v] = pre[u]+1;
            dfs(v);
            siz[u] += siz[v];
        }
    };
    for(int i=1;i<=n;i++) if(!siz[i]) dfs(i);
    vector<vector<int>> dp(tim+1, vector<int>(W+1));
    for(int i=0;i<tim;i++)
    {
        for(int j=pre[nfd[i]];j<=W-1;j++)
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+v[nfd[i]]);
        for(int j=pre[nfd[i]];j<=W;j++)
            dp[i+siz[nfd[i]]][j] = max(dp[i+siz[nfd[i]]][j], dp[i][j]);
    }
    cout<<dp[tim][W]<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
