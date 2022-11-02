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
const int maxn = 105;
vector<int> G[maxn];
int tim, dfn[maxn], low[maxn];
int cnt, scc[maxn], siz[maxn];
bool vis[maxn];
stack<int> st;
void tarjan(int u)
{
    low[u] = dfn[u] = ++tim;
    st.push(u);
    vis[u] = true;
    for(auto v : G[u])
    {
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        cnt++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            siz[cnt]++;
            scc[v] = cnt;
            vis[v] = false;
        }
        while(v!=u);
    }
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
    int n,W;
    cin>>n>>W;
    vector<int> w(n+1), o(n+1);
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) cin>>o[i];
    for(int i=1;i<=n;i++)
    {
        int f;
        cin>>f;
        if(f) G[f].push_back(i);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    vector<int> H[cnt+1];
    vector<int> din(cnt+1);
    vector<int> r(cnt+1), e(cnt+1);
    for(int u=1;u<=n;u++)
    {
        r[scc[u]] += w[u];
        e[scc[u]] += o[u];
        for(auto v : G[u])
            if(scc[u]!=scc[v])
                H[scc[u]].push_back(scc[v]), din[scc[v]]++;
    }
    for(int i=1;i<=cnt;i++) if(!din[i]) H[0].push_back(i);
    vector<vector<int>> dp(cnt+1, vector<int>(W+1));
    function<void(int)> dfs = [&](int u)
    {
        for(int i=r[u];i<=W;i++) dp[u][i] = e[u];
        for(auto v : H[u])
        {
            dfs(v);
            for(int j=W;j>=r[u];j--)
                for(int k=0;k<=j-r[u];k++)
                    dp[u][j] = max(dp[u][j], dp[u][j-k]+dp[v][k]);
        }
    };
    dfs(0);
    cout<<dp[0][W]<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
