#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 1e4+5;
struct E
{
    int to,next;
}Edge[maxn*20];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot].to=v;
    Edge[tot].next=Head[u];
    Head[u]=tot++;
}
inline int get(int a[])
{
    return a[0]*1000+a[1]*100+a[2]*10+a[3];
}
inline void set(int a[], int x)
{
    for(int i=3;i>=0;i--)
        a[i]=x%10, x/=10;
}
inline int add(int a[], int l, int r)
{
    int b[4];
    memcpy(b, a, sizeof(b));
    for(int i=l;i<=r;i++)
    {
        ++b[i];
        if(b[i]>9) b[i]=0;
    }
    int ret = 0;
    for(int i=0;i<4;i++)
        ret = ret * 10 + b[i];
    return ret;
}
inline int sub(int a[], int l,int r)
{
    int b[4];
    memcpy(b, a, sizeof(b));
    for(int i=l;i<=r;i++)
    {
        --b[i];
        if(b[i]<0) b[i]=9;
    }
    int ret = 0;
    for(int i=0;i<4;i++)
        ret = ret * 10 + b[i];
    return ret;
}
#include <queue>
int dep[maxn];
bool vis[maxn];
queue<int> q;
void bfs(int s)
{
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(vis[v]) continue;
            vis[v]=true;
            dep[v]=dep[u]+1;
            q.push(v);
        }
    }
}
inline int solve(int x,int y)
{
    int a[4], b[4];
    set(a, x); set(b, y);
    for(int i=0;i<4;i++)
    {
        b[i]=b[i]-a[i];
        if(b[i]<0) b[i]+=10;
    }
    return dep[get(b)];
}
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
    int a[4];
    for(int i=0;i<10000;i++)
    {
        set(a,i);
        for(int j=0;j<4;j++)
        {
            for(int k=j;k<4;k++)
            {
                AddEdge(i, add(a,j,k));
                AddEdge(i, sub(a,j,k));
            }
            
        }
    }
    bfs(0);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        cout<<solve(x,y)<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
