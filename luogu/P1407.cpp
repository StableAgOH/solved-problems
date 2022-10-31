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
int id;
unordered_map<string,int> mp;
int getid(const string& s)
{
    if(mp.find(s)==mp.end()) mp[s] = ++id;
    return mp[s];
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
    int n;
    cin>>n;
    vector<int> marry(n);
    for(int i=0;i<n;i++)
    {
        string u,v;
        cin>>v>>u;
        G[getid(u)].push_back(getid(v));
        marry[i] = getid(u);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string u,v;
        cin>>u>>v;
        G[getid(u)].push_back(getid(v));
    }
    for(size_t i=1;i<=mp.size();i++) if(!dfn[i]) tarjan(i);
    for(int i=0;i<n;i++) cout<<(siz[scc[marry[i]]]==1?"Safe":"Unsafe")<<'\n';
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
