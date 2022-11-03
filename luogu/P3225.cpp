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
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    __red(argc, argv);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t = 0;
    auto read = []() { int x; cin>>x; return x; };
    while(int m = read())
    {
        int n = 0;
        vector<pair<int,int>> edges(m);
        for(int i=0;i<m;i++)
        {
            cin>>edges[i].first>>edges[i].second;
            n = max({n, edges[i].first, edges[i].second});
        }
        vector<vector<int>> G(n+1);
        for(auto [u,v] : edges)
        {
            if(u==v) continue;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int tim;
        vector<int> dfn(n+1), low(n+1);
        stack<int> st;
        vector<bool> cut(n+1);
        vector<vector<int>> bcc;
        function<void(int,int)> tarjan = [&](int u,int f) {
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
        };
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
        ll x=0, y=1;
        for(auto&& v : bcc)
        {
            int p = 0;
            for(auto i : v) if(cut[i]) p++;
            int q = v.size();
            switch(p)
            {
            case 0: x += 2; y *= q*(q-1)/2; break;
            case 1: x++; y *= q-p; break;
            }
        }
        cout<<"Case "<<++t<<": "<<x<<' '<<y<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
