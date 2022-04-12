#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
const int maxn = 3e4+5;
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
struct Node { int l,r,sum,mx; } sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k)
{
    sgt[k].sum = sgt[ls(k)].sum+sgt[rs(k)].sum;
    sgt[k].mx = max(sgt[ls(k)].mx, sgt[rs(k)].mx);
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r)
    {
        sgt[k].sum = sgt[k].mx = w[l];
        return;
    }
    int m = (l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
    pushup(k);
}
void modify(int x,int z,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(l==r)
    {
        sgt[k].sum = sgt[k].mx = z;
        return;
    }
    int m = (l+r)>>1;
    if(x<=m) modify(x,z,ls(k));
    else modify(x,z,rs(k));
    pushup(k);
}
int query_sum(int x,int y,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].sum;
    int m = (l+r)>>1;
    int sum = 0;
    if(x<=m) sum += query_sum(x,y,ls(k));
    if(y>m)  sum += query_sum(x,y,rs(k));
    return sum;
}
int query_max(int x,int y,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].mx;
    int m = (l+r)>>1;
    int res = 0xcfcfcfcf;
    if(x<=m) res = query_max(x,y,ls(k));
    if(y>m)  res = max(res, query_max(x,y,rs(k)));
    return res;
}
void modify_v(int x,int z)
{
    modify(dfn[x], z);
}
int query_sum_p(int x,int y)
{
    int sum = 0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        sum += query_sum(dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    sum += query_sum(dfn[x], dfn[y]);
    return sum;
}
int query_max_p(int x,int y)
{
    int res = 0xcfcfcfcf;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        res = max(res, query_max(dfn[top[x]], dfn[x]));
        x = fa[top[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    res = max(res, query_max(dfn[x], dfn[y]));
    return res;
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
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v);
        AddEdge(v,u);
    }
    for(int i=1;i<=n;i++) cin>>v[i];
    dfs1(1,0);
    dfs2(1,1);
    build(1,n);
    int q;
    cin>>q;
    while(q--)
    {
        string opt;
        int x,y;
        cin>>opt>>x>>y;
        switch(opt[1])
        {
        case 'H':
            modify_v(x,y);
            break;
        case 'M':
            cout<<query_max_p(x,y)<<'\n';
            break;
        case 'S':
            cout<<query_sum_p(x,y)<<'\n';
            break;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
