#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 5e5+5;
struct E
{
    int to,next;
}Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot].to=v;
    Edge[tot].next=Head[u];
    Head[u]=tot++;
}
int siz[maxn],dep[maxn],son[maxn],fa[maxn];
void dfs1(int u,int f)
{
    fa[u]=f,dep[u]=dep[f]+1,siz[u]=1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
}
int top[maxn];
void dfs2(int u,int t)
{
    top[u]=t;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v=Edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int lca(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    return x;
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v);
        AddEdge(v,u);
    }
    dfs1(1,0);
    dfs2(1,1);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int x=lca(a,b),y=lca(a,c),z=lca(b,c);
        int ans;
        if(x==y) ans=z;
        else if(x==z) ans=y;
        else if(y==z) ans=x;
        cout<<ans<<' '<<dep[a]+dep[b]+dep[c]-dep[x]-dep[y]-dep[z]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
