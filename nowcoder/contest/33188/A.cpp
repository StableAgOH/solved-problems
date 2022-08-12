#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 1e5+5;
int n,k;
int q[maxn];
struct E { int to,next; } Edge[maxn<<1];
int tot,Head[maxn<<1];
void AddEdge(int u,int v) { Edge[tot] = {v,Head[u]}; Head[u] = tot++; }
int w[maxn<<1], c[maxn<<1];
bool isq[maxn<<1];
void dfs(int u)
{
    c[u] = isq[u];
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        dfs(v);
        c[u] += c[v];
    }
}
int find(int u,int x)
{
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(c[v]==x) return find(v,x);
    }
    return u;
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
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        cin>>q[i];
        isq[q[i]] = isq[q[i]+n] = true;
    }
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=2;i<=n;i++)
    {
        int f;
        cin>>f;
        AddEdge(f,i);
    }
    for(int i=1;i<=n;i++) cin>>w[i+n];
    for(int i=2;i<=n;i++)
    {
        int f;
        cin>>f;
        AddEdge(f+n,i+n);
    }
    dfs(1); dfs(1+n);
    int lca1=find(1,k), m1=find(lca1,k-1), s1=find(lca1,1);
    int lca2=find(1+n,k), m2=find(lca2,k-1), s2=find(lca2,1);
    int cnt = 0;
    for(int i=0;i<k;i++)
    {
        int w1=w[lca1], w2=w[lca2];
        if(m1!=lca1&&(q[i]==s1||q[i]==lca1)) w1 = w[m1];
        if(m2!=lca2&&(q[i]+n==s2||q[i]+n==lca2)) w2 = w[m2];
        if(w1>w2) cnt++;
    }
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
