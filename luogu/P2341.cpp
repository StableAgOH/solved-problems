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
const int maxn = 1e4+5;
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
        while(!st.empty())
        {
            int v = st.top();
            st.pop();
            siz[cnt]++;
            scc[v] = cnt;
            vis[v] = false;
            if(v==u) break;
        }
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
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    vector<bool> o(cnt+1);
    for(int u=1;u<=n;u++)
        for(auto v : G[u])
            if(scc[u]!=scc[v])
                o[scc[u]] = true;
    if(count(o.begin()+1, o.end(), false)==1) cout<<siz[find(o.begin()+1, o.end(), false)-o.begin()]<<'\n';
    else cout<<0<<'\n';
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
