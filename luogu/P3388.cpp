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
const int maxn = 2e4+5;
vector<int> G[maxn];
int tim, dfn[maxn], low[maxn];
bool cutv[maxn];
void tarjan(int u,int f)
{
    low[u] = dfn[u] = ++tim;
    int s = 0;
    for(auto v : G[u])
    {
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u] = min(low[u], low[v]);
            if(f&&low[v]>=dfn[u]) cutv[u] = true;
            else if(!f) s++;
        }
        low[u] = min(low[u], dfn[v]);
    }
    if(!f&&s>=2) cutv[u] = true;   // root
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
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
    cout<<count(cutv+1, cutv+1+n, true)<<endl;
    for(int i=1;i<=n;i++) if(cutv[i]) cout<<i<<' ';
    cout<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
