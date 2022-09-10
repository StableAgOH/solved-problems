#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <tuple>
#include <queue>
#include <vector>
#include <numeric>
#include <functional>
const int maxn = 2e5+5;
const int maxm = 4e5+5;
const int inf = 0x3f3f3f3f;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tp3;
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
        int n,m;
        cin>>n>>m;
        vector<tp3> G1[n+1], edges;
        for(int i=0;i<m;i++)
        {
            int u,v,w,h;
            cin>>u>>v>>w>>h;
            G1[u].emplace_back(v,w,h);
            G1[v].emplace_back(u,w,h);
            edges.emplace_back(h,u,v);
        }
        int rt = 1;
        vector<int> G2[2*n];
        vector<int> fa(2*n), val(2*n);
        val[0] = -1;
        iota(fa.begin(), fa.end(), 0);
        function<int(int)> find = [&](int x) { return x==fa[x]?x:fa[x]=find(fa[x]); };
        sort(edges.begin(), edges.end(), greater<>());
        int cnt = 0;
        for(auto&& [w,u,v] : edges)
        {
            int fu=find(u), fv=find(v);
            if(fu==fv) continue;
            cnt++;
            int x = n+cnt;
            val[x] = w;
            G2[x].push_back(fu);
            G2[fu].push_back(x);
            G2[x].push_back(fv);
            G2[fv].push_back(x);
            fa[fu] = fa[fv] = x;
            if(cnt==n-1)
            {
                rt = x;
                break;
            }
        }
        vector<int> dis(n+1);
        vector<bool> vis(n+1);
        auto dijkstra = [&](int s) {
            fill(dis.begin(), dis.end(), inf);
            dis[s] = 0;
            priority_queue<pii, vector<pii>, greater<>> pq;
            pq.emplace(0, s);
            while(!pq.empty())
            {
                int u = pq.top().second;
                pq.pop();
                if(vis[u]) continue;
                vis[u] = true;
                for(auto&& [v,w,h] : G1[u])
                {
                    if(dis[u]+w<dis[v])
                    {
                        dis[v] = dis[u]+w;
                        pq.emplace(dis[v], v);
                    }
                }
            }
        };
        dijkstra(1);
        vector<int> sh(2*n, inf);
        array<vector<int>, 20> acs;
        for(auto&& v : acs) v.resize(2*n);
        function<void(int,int)> dfs = [&](int u,int f) {
            acs[0][u] = f;
            for(int i=1;i<20;i++) acs[i][u] = acs[i-1][acs[i-1][u]];
            sh[u] = u>n?inf:dis[u];
            for(auto v : G2[u])
            {
                if(v==f) continue;
                dfs(v,u);
                sh[u] = min(sh[u], sh[v]);
            }
        };
        dfs(rt, 0);
        int q,k,s;
        cin>>q>>k>>s;
        int last = 0;
        while(q--)
        {
            int v,p;
            cin>>v>>p;
            v = (v+k*last-1)%n+1;
            p = (p+k*last)%(s+1);
            int u = v;
            for(int i=19;i>=0;i--) if(val[acs[i][u]]>p) u = acs[i][u];
            cout<<(last=sh[u])<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
