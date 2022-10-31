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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        while(x)
        {
            G[i].push_back(x);
            cin>>x;
        }
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    vector<int> din(cnt+1), dout(cnt+1);
    for(int u=1;u<=n;u++)
        for(auto v : G[u])
            if(scc[u]!=scc[v])
                din[scc[v]]++, dout[scc[u]]++;
    if(cnt==1) cout<<1<<endl<<0<<endl;
    else
    {
        auto cni = count(din.begin()+1, din.end(), 0);
        auto cno = count(dout.begin()+1, dout.end(), 0);
        cout<<cni<<endl;
        cout<<max(cni, cno)<<endl;
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
