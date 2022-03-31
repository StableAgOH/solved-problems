#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
#include <queue>
#include <cstring>
#include <numeric>
const int maxn = 1e3+5;
const int maxm = 1e5+5;
typedef pair<int,int> pii;
struct E { int to,w,next; };
class graph
{
private:
    E Edge[maxm];
    int tot,Head[maxn];
    int dis[maxn];
    bool vis[maxn];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
public:
    graph() { memset(Head,-1,sizeof(Head)); }
    void add_edge(int u,int v,int w)
    {
        Edge[tot]={v,w,Head[u]};
        Head[u]=tot++;
    }
    void dijkstra(int s=1)
    {
        memset(dis,0x3f,sizeof(dis));
        dis[s]=0;
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
                }
            }
        }
    }
    int get_ans(int n) { dijkstra(); return accumulate(dis+2, dis+1+n, 0); }
};
graph g1, g2;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g1.add_edge(u,v,w);
        g2.add_edge(v,u,w);
    }
    cout<<g1.get_ans(n)+g2.get_ans(n)<<endl;
    //======================================
    exit();
}