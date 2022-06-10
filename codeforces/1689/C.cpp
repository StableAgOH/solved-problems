#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <functional>
const int maxn = 1e5+5;
typedef long long ll;
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> G(n+1);
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> siz(n+1);
        function<void(int,int)> dfs1 = [&](int u,int f) {
            siz[u] = 1;
            for(auto v : G[u])
            {
                if(v==f) continue;
                dfs1(v, u);
                siz[u] += siz[v];
            }
        };
        dfs1(1, 0);
        function<int(int,int)> dfs2 = [&](int u,int f) {
            if(G[u].size()==1&&u!=1) return 0;
            if(u==1&&G[u].size()==1||u!=1&&G[u].size()==2) return siz[u]-2;
            int p=0, q=0;
            for(auto v : G[u])
            {
                if(v==f) continue;
                if(!p) p = v;
                else q = v;
            }
            return max(dfs2(p,u)+siz[q]-1, dfs2(q,u)+siz[p]-1);
        };
        cout<<dfs2(1, 0)<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
