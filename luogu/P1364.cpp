#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e5+5;
struct E
{
    int to,next;
}Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot]={v,Head[u]};
    Head[u]=tot++;
}
int v[maxn];
int ans=0x3f3f3f3f, siz[maxn], dp[maxn];
void dfs1(int u,int f=0,int dep=0)
{
    siz[u]=v[u];
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs1(v,u,dep+1);
        siz[u]+=siz[v];
    }
    dp[1]+=v[u]*dep;
}
void dfs2(int u,int f=0)
{
    ans = min(ans, dp[u]);
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dp[v]=dp[u]+siz[1]-(siz[v]<<1);
        dfs2(v,u);
    }
}
#include <cstring>
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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int v1,v2;
        cin>>v[i]>>v1>>v2;
        if(v1)
        {
            AddEdge(i,v1);
            AddEdge(v1,i);
        }
        if(v2)
        {
            AddEdge(i,v2);
            AddEdge(v2,i);
        }
    }
    dfs1(1);
    dfs2(1);
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
