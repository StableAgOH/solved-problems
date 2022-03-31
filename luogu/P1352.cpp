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
const int maxn = 6e3+5;
int v[maxn], dp[maxn][2];
bool fa[maxn];
struct E
{
    int to,next;
}Edge[maxn];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot]={v,Head[u]};
    Head[u]=tot++;
}
void dfs(int u,int f)
{
    dp[u][1] += v[u];
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs(v,u);
        dp[u][0]+=max(dp[v][0], dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
}
#include <cstring>
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
    memset(Head, -1, sizeof(Head));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<n;i++)
    {
        int u,f;
        cin>>u>>f;
        fa[u]=true;
        AddEdge(f, u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!fa[i])
        {
            dfs(i, 0);
            cout<<max(dp[i][0], dp[i][1])<<endl;
            break;
        }
    }
    //======================================
    exit();
}