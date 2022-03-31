#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cstring>
#include <queue>
const int maxn = 55;
const int maxm = 1e5+5;
struct E
{
    int to,next;
}Edge[maxm];
int tot,Head[maxn];
void add_edge(int u,int v)
{
    Edge[tot]={v,Head[u]};
    Head[u]=tot++;
}
bool dp[maxn][maxn][40];
#include <queue>
typedef pair<int,int> pii;
queue<pii> q;
bool vis[maxn];
int bfs(int s, int e)
{
    q.emplace(s,0);
    while(!q.empty())
    {
        auto [u,d] = q.front();
        q.pop();
        if(u==e) return d;
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(vis[v]) continue;
            vis[v]=true;
            q.emplace(v, d+1);
        }
    }
    return -233;
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
        add_edge(u,v);
        dp[u][v][0]=true;
    }
    for(int k=1;k<=32;k++)
        for(int u=1;u<=n;u++)
            for(int v=1;v<=n;v++)
                for(int w=1;w<=n;w++)
                    if(dp[u][v][k-1]&&dp[v][w][k-1])
                        add_edge(u,w), dp[u][w][k]=true;
    cout<<bfs(1,n)<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}