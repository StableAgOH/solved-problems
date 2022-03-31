#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cstring>
#include <queue>
const int maxn = 1e6+5;
const int maxm = 2e6+5;
const int mod = 1e5+3;
typedef pair<int,int> pii;
struct E
{
    int to,w,next;
}Edge[maxm<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v,int w)
{
    Edge[tot]={v,w,Head[u]};
    Head[u]=tot++;
}
int cnt[maxn], dis[maxn];
bool vis[maxn];
priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijkstra(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    cnt[s]=1;
    pq.emplace(0,s);
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(dis[u]+Edge[i].w<dis[v])
            {
                dis[v]=dis[u]+Edge[i].w;
                pq.emplace(dis[v],v);
                cnt[v]=cnt[u];
            }
            else if(dis[u]+Edge[i].w==dis[v])
                cnt[v] = (cnt[v]+cnt[u])%mod;
        }
    }
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    memset(Head,-1,sizeof(Head));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v,1);
        AddEdge(v,u,1);
    }
    dijkstra(1);
    for(int i=1;i<=n;i++) cout<<cnt[i]<<'\n';
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}