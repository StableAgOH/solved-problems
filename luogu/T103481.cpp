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
const int maxn = 5e4+5;
const int maxm = 3e5+5;
typedef pair<int,int> pii;
vector<pii> G[maxn];
int tim, dfn[maxn], low[maxn];
bool cut[maxm];
int cnt, bcc[maxn];
void tarjan(int u,int f)
{
    low[u] = dfn[u] = ++tim;
    for(auto [v,id] : G[u])
    {
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u] = min(low[u], low[v]);
            if(low[v]>dfn[u]) cut[id] = true;
        }
        else if(v!=f) low[u] = min(low[u], dfn[v]);
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
        if(u==v) continue;
        G[u].emplace_back(v,i);
        G[v].emplace_back(u,i);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
    cout<<count(cut+1, cut+1+m, true)<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
