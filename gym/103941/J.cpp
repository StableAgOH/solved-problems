#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 1e6+5;
struct E { int to,next; } Edge[maxn<<1];
int tot,Head[maxn];
void AddEdge(int u,int v)
{
    Edge[tot] = {v,Head[u]};
    Head[u] = tot++;
}
int a[maxn], b[maxn], mn[maxn], siz[maxn];
void dfs(int u,int f)
{
    mn[u] = a[u];
    siz[u] = 1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs(v,u);
        mn[u] = min(mn[u], mn[v]);
        siz[u] += siz[v];
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
    int rt = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[a[i]] = i;
        if(!a[i]) rt = i;
    }
    for(int i=2;i<=n;i++)
    {
        int f;
        cin>>f;
        AddEdge(f,i);
        AddEdge(i,f);
    }
    dfs(rt, 0);
    int mx = 0;
    for(int i=Head[rt];~i;i=Edge[i].next) mx = max(mx, siz[Edge[i].to]);
    cout<<mx<<' ';
    for(int i=1;i<n;i++) cout<<(mn[b[i]]<i?0:n-siz[b[i]])<<' ';
    cout<<n<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
