#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <queue>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
const int maxn = 1e5+5;
const int maxm = 2e5+5;
const int maxk = 5e5+5;
const long long INF = 0x3f3f3f3f3f3f3f3f;
typedef long long ll;
typedef pair<ll,int> pii;
struct E { int to; ll w; int next;  } Edge[maxm<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v,ll w)
{
    Edge[tot] = {v,w,Head[u]};
    Head[u] = tot++;
}
int n;
struct Node { int l,r,val,dep; } trie[maxk];
void build(int k=1,int dep=0)
{
    if(k>n) return;
    trie[k].val = k;
    trie[k].dep = dep;
    build(k<<1, dep+1);
    build(k<<1|1, dep+1);
}
priority_queue<pii, vector<pii>, greater<pii>> pq;
bool vis[maxn];
unordered_map<int,ll> dis[maxn];
void dijkstra(int s)
{
    memset(vis,false,sizeof(vis));
    dis[s][s] = 0;
    pq.emplace(0,s);
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]||trie[u].dep<trie[s].dep) continue;
        vis[u] = true;
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            ll k;
            if(dis[s].find(v)==dis[s].end()) k = INF;
            else k = dis[s][v];
            if(dis[s][u]+Edge[i].w<k)
            {
                dis[s][v] = dis[s][u]+Edge[i].w;
                pq.emplace(dis[s][v], v);
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
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    memset(Head,-1,sizeof(Head));
    int m;
    cin>>n>>m;
    build();
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        AddEdge(u,v,w);
        AddEdge(v,u,w);
    }
    for(int i=1;i<=n;i++) dijkstra(i);
    int q;
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int x=u, y=v;
        if(trie[x].dep<trie[y].dep) swap(x,y);
        while(trie[x].dep>trie[y].dep) x /= 2;
        while(x!=y) x/=2, y/=2;
        ll ans = INF;
        while(x)
        {
            int r = trie[x].val;
            x /= 2;
            if(dis[r].find(u)==dis[r].end()||dis[r].find(v)==dis[r].end()) continue;
            ans = min(ans, dis[r][u]+dis[r][v]);
        }
        cout<<(ans==INF?-1:ans)<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
