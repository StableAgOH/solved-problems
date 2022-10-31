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
const int maxn = 5e5+5;
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
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int f;
        cin>>f;
        for(int j=1;j<n;j++)
        {
            int u;
            cin>>u;
            G[f].push_back(u);
            f = u;
        }
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    int pre = 0;
    vector<int> ans(cnt+1);
    for(int i=cnt;i>=1;i--)
    {
        ans[i] = pre;
        pre += siz[i];
    }
    for(int i=1;i<=n;i++) cout<<n-ans[scc[i]]-1<<' ';
    cout<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
