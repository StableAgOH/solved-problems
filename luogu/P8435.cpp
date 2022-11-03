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
int rt;
int tim, dfn[maxn], low[maxn];
stack<int> st;
bool cut[maxn];
vector<vector<int>> bcc;
void tarjan(int u,int f)
{
    low[u] = dfn[u] = ++tim;
    st.push(u);
    if(!f&&G[u].empty())
    {
        bcc.emplace_back(1,u);
        return;
    }
    int s = 0;
    for(auto v : G[u])
    {
        if(!dfn[v])
        {
            tarjan(v,u);
            low[u] = min(low[u], low[v]);
            if(low[v]>=dfn[u])
            {
                s++;
                if(f||s>1) cut[u] = true;
                bcc.emplace_back();
                int w;
                do
                {
                    w = st.top();
                    st.pop();
                    bcc.back().push_back(w);
                }
                while(w!=v);
                bcc.back().push_back(u);
            }
        }
        else low[u] = min(low[u], dfn[v]);
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
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
    cout<<bcc.size()<<'\n';
    for(auto&& v : bcc)
    {
        cout<<v.size();
        for(auto i : v) cout<<' '<<i;
        cout<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}