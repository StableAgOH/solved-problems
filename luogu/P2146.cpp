#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
const int maxn = 1e5+5;
int v[maxn];
struct E { int to,next; } Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot] = {v,Head[u]};
    Head[u] = tot++;
}
int dep[maxn], son[maxn], fa[maxn], siz[maxn];
void dfs1(int u,int f)
{
    siz[u] = 1;
    fa[u] = f;
    dep[u] = dep[f]+1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if(siz[v]>siz[son[u]]) son[u] = v;
    }
}
int tim, dfn[maxn], top[maxn], w[maxn];
void dfs2(int u,int t)
{
    top[u] = t;
    dfn[u] = ++tim;
    w[tim] = v[u];
    if(!son[u]) return;
    dfs2(son[u], t);
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
struct Node { int l,r,f,val; } sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k) { sgt[k].val = sgt[ls(k)].val+sgt[rs(k)].val; }
inline void pushdw(int k)
{
    int f=sgt[k].f; sgt[k].f=-1;
    sgt[ls(k)].f = sgt[rs(k)].f = f;
    sgt[ls(k)].val = (sgt[ls(k)].r-sgt[ls(k)].l+1)*f;
    sgt[rs(k)].val = (sgt[rs(k)].r-sgt[rs(k)].l+1)*f;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r, sgt[k].f=-1;
    if(l==r)
    {
        sgt[k].val = w[l];
        return;
    }
    int m = (l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
    pushup(k);
}
void modify(int x,int y,int z,int k=1)
{
    int l=sgt[k].l,r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f=z;
        sgt[k].val=(r-l+1)*z;
        return;
    }
    if(~sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) modify(x,y,z,ls(k));
    if(y>m) modify(x,y,z,rs(k));
    pushup(k);
}
void modify_c(int x,int y)
{
    while(top[y]!=1)
    {
        modify(dfn[top[y]],dfn[y],1);
        y = fa[top[y]];
    }
    modify(dfn[x],dfn[y],1);
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
        int f;
        cin>>f;
        f++;
        AddEdge(f,i);
        AddEdge(i,f);
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,n);
    int q;
    cin>>q;
    while(q--)
    {
        string opt;
        int x;
        cin>>opt>>x;
        x++;
        int tmp = sgt[1].val;
        if(opt[0]=='i') modify_c(1,x);
        else modify(dfn[x],dfn[x]+siz[x]-1,0);
        cout<<abs(sgt[1].val-tmp)<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
