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
const int maxn = 1e5+5;
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
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    vector<int> H[cnt+1];
    for(int u=1;u<=n;u++)
        for(auto v : G[u])
            if(scc[u]!=scc[v])
                H[scc[u]].push_back(scc[v]);
    vector<int> f(cnt+1), g(cnt+1);
    for(int i=1;i<=cnt;i++) f[i]=siz[i], g[i]=1;
    for(int u=cnt;u>=1;u--)
    {
        unordered_set<int> s;
        for(auto v : H[u])
        {
            if(s.find(v)!=s.end()) continue;
            s.insert(v);
            if(f[u]+siz[v]>f[v])
            {
                f[v] = f[u]+siz[v];
                g[v] = g[u];
            }
            else if(f[u]+siz[v]==f[v]) g[v] = (g[v]+g[u])%p;
        }
    }
    auto x = *max_element(f.begin()+1, f.end());
    cout<<x<<endl;
    int s = 0;
    for(int i=1;i<=cnt;i++) if(f[i]==x) s = (s+g[i])%p;
    cout<<s<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
