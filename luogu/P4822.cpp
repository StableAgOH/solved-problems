#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
#include <queue>
const int maxk = 50;
const int maxn = 50*(maxk+1)+5;
const int maxm = (1e3*(maxk*2+1))*2+maxk+5;
typedef pair<int,int> pii;
struct E { int to,w,next; } Edge[maxm];
int tot,Head[maxn];
inline void AddEdge(int u,int v,int w)
{
    Edge[tot] = {v,w,Head[u]};
    Head[u] = tot++;
}
int dis[maxn];
bool vis[maxn];
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
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(dis[u]+Edge[i].w<dis[v])
            {
                dis[v] = dis[u]+Edge[i].w;
                pq.emplace(dis[v], v);
            }
        }
    }
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
    memset(Head, -1, sizeof(Head));
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        for(int j=0;j<=k;j++)
        {
            AddEdge(u+j*n, v+j*n, w);
            AddEdge(v+j*n, u+j*n, w);
            if(j==k) continue;
            AddEdge(u+j*n, v+(j+1)*n, w/2);
            AddEdge(v+j*n, u+(j+1)*n, w/2);
        }
    }
    for(int i=1;i<=k;i++) AddEdge(n+(i-1)*n, n+i*n, 0);
    dijkstra(1);
    cout<<dis[n+k*n]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
