#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 3e5 + 5;
struct E
{
    int to,next;
}Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot]=(E){v,Head[u]};
    Head[u]=tot++;
}
int son[maxn], dep[maxn], fa[maxn];
long long siz[maxn];
void dfs1(int u,int f=0)
{
    dep[u]=dep[f]+1, fa[u]=f, siz[u]=1;
    int maxsize = -1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs1(v, u);
        siz[u]+=siz[v];
        if(siz[v]>maxsize)
        {
            maxsize = siz[v];
            son[u]=v;
        }
    }
}
int top[maxn];
void dfs2(int u,int t=0)
{
    top[u]=t;
    if(son[u]) dfs2(son[u], t);
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v, v);
    }
}
pair<int,int> lca(int x,int y)
{
    int last;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        last = top[x];
        x = fa[top[x]];
    }
    return make_pair(dep[x]<dep[y]?x:y, x==y?last:dep[x]<dep[y]?son[x]:son[y]);
}
#include <cstring>
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    memset(Head, -1, sizeof(Head));
    int x,y;
    long long n;
    cin>>n>>x>>y;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v);
        AddEdge(v,u);
    }
    dfs1(1);
    dfs2(1);
    pair<int,int> p = lca(x,y);
    int f = p.first;
    int s = p.second;
    long long ans;
    if(f==x) ans = n*(n-1-siz[y])+siz[s]*siz[y];
    else if(f==y)
        ans = n*(n-1-siz[x])+siz[s]*siz[x];
    else ans = (n*(n-1)-siz[x]*siz[y]);
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}