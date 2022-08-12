#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 2e6+5;
struct E { int to,next; } Edge[maxn<<1];
int tot, Head[maxn];
void AddEdge(int u,int v) { Edge[tot]={v,Head[u]}; Head[u]=tot++; }
int fa[22][maxn];
void dfs1(int u,int f)
{
    fa[0][u] = f;
    for(int i=1;i<=21;i++)
        fa[i][u] = fa[i-1][fa[i-1][u]];
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs1(v, u);
    }
}
int c[maxn];
void dfs2(int u,int f)
{
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(v==f) continue;
        dfs2(v,u);
        c[u] += c[v];
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
    dfs1(1,1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        int u = i;
        for(int j=21;x;j--)
        {
            if(x>=(1<<j))
            {
                x -= (1<<j);
                u = fa[j][u];
            }
        }
        c[i]++;
        if(u==1) c[0]--;
        else c[fa[0][u]]--;
    }
    dfs2(1,0);
    for(int i=1;i<=n;i++) cout<<c[i]<<' ';
    cout<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
