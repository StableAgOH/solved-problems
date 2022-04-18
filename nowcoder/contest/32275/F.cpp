#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <queue>
#include <cstring>
const int maxn = 1005;
typedef pair<int,int> pii;
vector<pii> G[maxn];
vector<int> pre[maxn];
bool vis[maxn];
int dis[maxn];
priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    pq.emplace(0, s);
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v,w] : G[u])
        {
            if(dis[u]+w<dis[v])
            {
                dis[v] = dis[u]+w;
                pq.emplace(dis[v], v);
                pre[v].clear();
                pre[v].push_back(u);
            }
            else if(dis[u]+w==dis[v]) pre[v].push_back(u);
        }
    }
}
bool b[maxn];
void dfs(int u)
{
    b[u] = true;
    for(auto v : pre[u]) if(!b[v]) dfs(v);
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].emplace_back(v,w);
    }
    dijkstra(1);
    dfs(n);
    while(k--)
    {
        int u;
        cin>>u;
        cout<<(b[u]?"yes":"no")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
