#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <iomanip>
#include <algorithm>
#include <cstring>
const int maxn = 3005;
const int maxm = 1e4+5;
const long double eps = 1e-10;
struct E { int to,next; double w; } Edge[maxm];
int tot,Head[maxn];
inline void AddEdge(int u,int v,double w)
{
    Edge[tot] = {v,Head[u],w};
    Head[u] = tot++;
}
int n,k;
long double dis[maxn];
bool vis[maxn];
long double m;
bool spfa(int u)
{
    vis[u] = true;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(dis[v]>dis[u]+Edge[i].w-m)
        {
            dis[v] = dis[u]+Edge[i].w-m;
            if(vis[v]||spfa(v)) return true;
        }
    }
    vis[u] = false;
    return false;
}
bool check()
{
    fill(dis+1, dis+1+n, 1e9);
    memset(vis, false, sizeof(vis));
    for(int i=1;i<=n;i++) if(spfa(i)) return true;
    return false;
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
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int u,v;
        double w;
        cin>>u>>v>>w;
        AddEdge(u,v,w);
    }
    long double l=-1e7, r=1e7;
    while(r-l>eps)
    {
        m = (l+r)/2;
        if(check()) r = m;
        else l = m;
    }
    cout<<fixed<<setprecision(8)<<l<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
