#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
struct E
{
    int to,w,cnt,next;
}Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v,int w,int k)
{
    Edge[tot].to=v;
    Edge[tot].w=w;
    Edge[tot].cnt=k;
    Edge[tot].next=Head[u];
    Head[u]=tot++;
}
int s[maxn],v[maxn],w[maxn];
int fa[maxn],dep[maxn],siz[maxn],son[maxn];
void dfs1(int u,int f)
{
    fa[u]=f,dep[u]=dep[f]+1,siz[u]=1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int to = Edge[i].to;
        if(to==f) continue;
        v[to]=Edge[i].w;
        s[Edge[i].cnt]=to;
        dfs1(to,u);
        siz[u]+=siz[to];
        if(siz[to]>siz[son[u]]) son[u]=to;
    }
}
int tim,dfn[maxn],top[maxn];
void dfs2(int u,int t)
{
    dfn[u]=++tim;
    w[tim]=v[u];
    top[u]=t;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
struct Node
{
    int l,r,f1,f2,val;
}sgt[maxn<<2];
inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1|1; }
inline void pushup(int k)
{
    sgt[k].val=max(sgt[ls(k)].val,sgt[rs(k)].val);
}
inline void pushdw(int k)
{
    int l=ls(k),r=rs(k);
    if(~sgt[k].f1)
    {
        sgt[l].f2=sgt[r].f2=0;
        sgt[l].val=sgt[r].val=sgt[l].f1=sgt[r].f1=sgt[k].f1;
        sgt[k].f1=-1;
    }
    if(sgt[k].f2)
    {
        sgt[l].f2+=sgt[k].f2;
        sgt[r].f2+=sgt[k].f2;
        sgt[l].val+=sgt[k].f2;
        sgt[r].val+=sgt[k].f2;
        sgt[k].f2=0;
    }
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l,sgt[k].r=r,sgt[k].f1=-1;
    if(l==r)
    {
        sgt[k].val=w[l];
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
        sgt[k].f1=sgt[k].val=z;
        sgt[k].f2=0;
        return;
    }
    pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) modify(x,y,z,ls(k));
    if(y>m) modify(x,y,z,rs(k));
    pushup(k);
}
void add(int x,int y,int z,int k=1)
{
    int l=sgt[k].l,r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f2+=z;
        sgt[k].val+=z;
        return;
    }
    pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) add(x,y,z,ls(k));
    if(y>m) add(x,y,z,rs(k));
    pushup(k);
}
#include <climits>
int query(int x,int y,int k=1)
{
    int l=sgt[k].l,r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].val;
    pushdw(k);
    int m = (l+r)>>1;
    int ret = INT_MIN;
    if(x<=m) ret=max(ret,query(x,y,ls(k)));
    if(y>m) ret=max(ret,query(x,y,rs(k)));
    return ret;
}
void modifyc(int x,int y,int z)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        modify(dfn[top[x]],dfn[x],z);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y) modify(dfn[x]+1,dfn[y],z);
}
void addc(int x,int y,int z)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        add(dfn[top[x]],dfn[x],z);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y) add(dfn[x]+1,dfn[y],z);
}
int queryc(int x,int y)
{
    int ret=INT_MIN;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        ret=max(ret,query(dfn[top[x]],dfn[x]));
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    if(x!=y) ret=max(ret,query(dfn[x]+1,dfn[y]));
    return ret;
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
        int u,v,w;
        cin>>u>>v>>w;
        AddEdge(u,v,w,i);
        AddEdge(v,u,w,i);
    }
    dfs1(1,1);
    dfs2(1,1);
    build(1,n);
    while(true)
    {
        string str;
        cin>>str;
        int u,v,w;
        switch(str[1])
        {
        case 'h':
            cin>>u>>w;
            modify(dfn[s[u]],dfn[s[u]],w);
            break;
        case 'o':
            cin>>u>>v>>w;
            modifyc(u,v,w);
            break;
        case 'd':
            cin>>u>>v>>w;
            addc(u,v,w);
            break;
        case 'a':
            cin>>u>>v;
            cout<<queryc(u,v)<<endl;
            break;
        default: goto end;
        }
    }
end:
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
