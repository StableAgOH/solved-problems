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
    int n,m;
    cin>>n>>m;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<ll>> dis(n+1, vector<ll>(n+1, 1e18));
    for(int i=1;i<=n;i++) dis[i][i] = 0;
    for(int i=0;i<m;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    ll mn = 1e18;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ll sum = 0;
            for(int k=1;k<=n;k++)
                sum += min(dis[k][i], dis[k][j])*a[k];
            mn = min(mn, sum);
        }
    }
    cout<<mn<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
