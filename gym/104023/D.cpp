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
int len[] = {0,3,4,5,4,3}, pre[5];
inline int id(int x,int y) { return pre[x-1]+y-1; }
vector<tuple<int,int,int>> G[20];
inline void ae(int u,int v,int x,int y)
{
    G[u].emplace_back(v, x, y);
    G[v].emplace_back(u, x, y);
}
int w[20];
ll dp[(1<<19)+5];
ll dfs(int u)
{
    if(~dp[u]) return dp[u];
    ll mx = 0;
    for(int p=0;p<19;p++)
    {
        if(!(u&(1<<p))) continue;
        int v = u^(1<<p);
        mx = max(mx, dfs(v));
        for(auto [q,x,y] : G[p])
        {
            int r = id(x,y);
            if(!(u&(1<<r))) continue;
            if(u&(1<<q)) continue;
            mx = max(mx, dfs((v^(1<<r))|(1<<q))+w[r]);
        }
    }
    return dp[u] = mx;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    __red(argc, argv);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    for(int i=1;i<5;i++) pre[i] = pre[i-1]+len[i];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    ae(id(1,1),id(1,3),1,2); ae(id(1,1),id(3,1),2,1); ae(id(1,1),id(3,3),2,2);
    ae(id(1,2),id(3,2),2,2); ae(id(1,2),id(3,4),2,3);
    ae(id(1,3),id(3,3),2,3); ae(id(1,3),id(3,5),2,4);
    ae(id(2,1),id(2,3),2,2); ae(id(2,1),id(4,2),3,2);
    ae(id(2,2),id(2,4),2,3); ae(id(2,2),id(4,1),3,2); ae(id(2,2),id(4,3),3,3);
    ae(id(2,3),id(4,2),3,3); ae(id(2,3),id(4,4),3,4);
    ae(id(2,4),id(4,3),3,4);
    ae(id(3,1),id(3,3),3,2); ae(id(3,1),id(5,1),4,1);
    ae(id(3,2),id(3,4),3,3); ae(id(3,2),id(5,2),4,2);
    ae(id(3,3),id(3,5),3,4); ae(id(3,3),id(5,1),4,2); ae(id(3,3),id(5,3),4,3);
    ae(id(3,4),id(5,2),4,3);
    ae(id(3,5),id(5,3),4,4);
    ae(id(4,1),id(4,3),4,2);
    ae(id(4,2),id(4,4),4,3);
    ae(id(5,1),id(5,3),5,2);
    for(int i=0;i<19;i++) cin>>w[i];
    int t;
    cin>>t;
    while(t--)
    {
        int u = 0;
        for(int i=1;i<=5;i++)
        {
            cin.get();
            for(int j=1;j<=len[i];j++)
                if(cin.get()=='#')
                    u |= (1<<id(i,j));
        }
        cout<<dfs(u)<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
