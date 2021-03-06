#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
struct E
{
    int to,next;
}Edge[maxn];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot]=(E){v,Head[u]};
    Head[u]=tot++;
}
int dp[maxn];
void dfs(int u)
{
    int sum = 0, mx = 0;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        sum++;
        dfs(v);
        mx = max(mx, dp[v]);
    }
    dp[u] = mx + sum;
}
#include <cstring>
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
    memset(Head,-1,sizeof(Head));
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int fa;
        cin>>fa;
        AddEdge(fa,i);
    }
    dfs(1);
    cout<<dp[1]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
