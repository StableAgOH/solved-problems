#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e5+5;
typedef long long ll;
struct E { int to,w,next; } Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v,int w)
{
    Edge[tot]={v,w,Head[u]};
    Head[u]=tot++;
}
int siz[maxn], son[maxn];
ll val[maxn];
void df1(int u,int f)
{
    siz[u]=1;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        df1(v,u);
        val[v]=Edge[i].w;
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])
            son[u]=v;
    }
}
int cnt[maxn];
ll sum, ans[maxn];
int flag_son;
void dfs2(int u,int f,int z)
{
    sum -= (val[u]*cnt[val[u]])*(val[u]*cnt[val[u]]);
    cnt[val[u]]+=z;
    sum += (val[u]*cnt[val[u]])*(val[u]*cnt[val[u]]);
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f||v==flag_son) continue;
        dfs2(v,u,z);
    }
}
void dfs3(int u,int f,bool keep)
{
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f||v==son[u]) continue;
        dfs3(v,u,false);
    }
    if(son[u])
    {
        dfs3(son[u],u,true);
        flag_son = son[u];
    }
    dfs2(u, f, 1);
    flag_son = 0;
    ans[u] = sum+val[u]*val[u]*(1-2*cnt[val[u]]);
    if(!keep)
    {
        dfs2(u,f,-1);
        sum=0;
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
    int n,m,c;
    cin>>n>>m>>c;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        AddEdge(u,v,w);
        AddEdge(v,u,w);
    }
    df1(1,0);
    dfs3(1,0,0);
    // for(int i=1;i<=n;i++)
    //     cout<<val[i]<<' ';
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<ans[i]<<' ';
    // cout<<endl;
    while(m--)
    {
        int q;
        cin>>q;
        cout<<ans[q]<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
