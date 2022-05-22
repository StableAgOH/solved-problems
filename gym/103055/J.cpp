#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <queue>
#include <cstring>
const int maxn = 3005;
int v[maxn];
int dp[maxn<<1];
struct E { int to,next; } Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot] = {v,Head[u]};
    Head[u] = tot++;
}
queue<int> q;
bool vis[maxn];
int dep[maxn];
void bfs(int s)
{
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(vis[v]) continue;
            vis[v] = true;
            dep[v] = dep[u]+1;
            q.push(v);
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
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=2;i<=n;i++) cin>>v[i];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v);
        AddEdge(v,u);
    }
    bfs(1);
    for(int i=1;i<=n;i++)
    {
        int w = dep[i]<<1;
        for(int j=w;j<=t;j++)
            dp[j] = max(dp[j], dp[j-w]+v[i]);
    }
    for(int i=1;i<=t;i++) cout<<dp[i]<<' ';
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
