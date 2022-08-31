#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <queue>
#include <vector>
#include <cstring>
#include <unordered_map>
const int maxn = 5e5+5;
const int maxm = 1e7+5;
typedef long long ll;
typedef pair<int,int> pii;
int e[maxn][4];
struct H { inline ll operator()(const pii& p) const { return ll(p.first)*maxn+p.second; } };
unordered_map<pii, int, H> mp;
struct E { int to,w,next; } Edge[maxm<<2];
int tot, Head[maxm];
void AddEdge(int u,int v,int w) { Edge[tot]={v,w,Head[u]}; Head[u]=tot++; }
int dis[maxm];
bool vis[maxm];
deque<int> dq;
void bfs(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    dq.push_front(s);
    while(!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v=Edge[i].to, w=Edge[i].w;
            if(dis[u]+w<dis[v])
            {
                dis[v] = dis[u]+w;
                if(w) dq.push_back(v);
                else dq.push_front(v);
            }
        }
    }
}
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
    memset(Head, -1, sizeof(Head));
    int n;
    cin>>n;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>e[i][j];
            auto p = pii(i, e[i][j]);
            auto q = pii(e[i][j], i);
            if(mp.find(p)==mp.end()) mp[p] = ++cnt;
            if(mp.find(q)==mp.end()) mp[q] = ++cnt;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<4;j++)
        {
            int x = e[i][j];
            if(!x) continue;
            for(int k=0;k<4;k++)
            {
                int t = e[x][k];
                if(!t) continue;
                AddEdge(mp[{i,x}], mp[{x,t}], e[x][(k+3)%4]!=i);
            }
        }
    }
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    bfs(mp[{a,b}]);
    int t = mp[{c,d}];
    cout<<(dis[t]==0x3f3f3f3f?-1:dis[t])<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
