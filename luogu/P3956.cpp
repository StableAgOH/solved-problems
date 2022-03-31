#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <queue>
#include <cstring>
const int maxn = 1.1e4;
const int maxm = maxn*12;
typedef pair<int,int> pii;
struct E { int to,w,next; } Edge[maxm];
int tot,Head[maxn];
inline void AddEdge(int u,int v,int w)
{
    Edge[tot]={v,w,Head[u]};
    Head[u]=tot++;
}
int dis[maxn];
bool vis[maxn];
priority_queue<pii,vector<pii>,greater<pii>> pq;
void dijkstra(int s)
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
int board[105][105];
inline int hs(int x,int y) { return x*105+y; }
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
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        board[x+1][y+1]=c+1;
    }
    int p[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int q[8][2] = {{-1,-1}, {-1,1}, {1,-1}, {1,1}, {-2,0}, {2,0}, {0,-2}, {0,2}};
    for(int i=2;i<=m+1;i++)
    {
        for(int j=2;j<=m+1;j++)
        {
            if(!board[i][j]) continue;
            for(int k=0;k<4;k++)
            {
                int x=i+p[k][0], y=j+p[k][1];
                if(!board[x][y]) continue;
                if(board[x][y]==board[i][j]) AddEdge(hs(i,j), hs(x,y), 0);
                else AddEdge(hs(i,j), hs(x,y), 1);
            }
            for(int k=0;k<8;k++)
            {
                int x=i+q[k][0], y=j+q[k][1];
                if(!board[x][y]) continue;
                if(board[x][y]==board[i][j]) AddEdge(hs(i,j), hs(x,y), 2);
                else AddEdge(hs(i,j), hs(x,y), 3);
            }
        }
    }
    if(!board[m+1][m+1])
    {
        if(board[m][m+1]) AddEdge(hs(m,m+1), hs(m+1,m+1), 2);
        if(board[m+1][m]) AddEdge(hs(m+1,m), hs(m+1,m+1), 2);
    }
    dijkstra(hs(2,2));
    int ans = dis[hs(m+1,m+1)];
    cout<<(ans>1e9?-1:ans)<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}