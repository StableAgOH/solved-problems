#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 2e5+5;
struct Node { int l,r,val; } hjt[maxn*40];
int cnt, rootfa[maxn], rootdep[maxn];
void build(int l,int r,int& k)
{
    k = ++cnt;
    if(l==r)
    {
        hjt[k].val = l;
        return;
    }
    int m = (l+r)>>1;
    build(l,m,hjt[k].l);
    build(m+1,r,hjt[k].r);
}
void modify(int l,int r,int ver,int& k,int p,int z)
{
    hjt[k=++cnt] = hjt[ver];
    if(l==r)
    {
        hjt[k].val = z;
        return;
    }
    int m = (l+r)>>1;
    if(p<=m) modify(l,m,hjt[ver].l,hjt[k].l,p,z);
    else modify(m+1,r,hjt[ver].r,hjt[k].r,p,z);
}
int query(int l,int r,int k,int p)
{
    if(l==r) return hjt[k].val;
    int m = (l+r)>>1;
    if(p<=m) return query(l,m,hjt[k].l,p);
    else return query(m+1,r,hjt[k].r,p);
}
int n;
int find(int ver,int x)
{
    int fx = query(1,n,rootfa[ver],x);
    return fx==x?x:find(ver,fx);
}
void merge(int ver,int x,int y)
{
    x = find(ver-1, x);
    y = find(ver-1, y);
    if(x==y)
    {
        rootfa[ver] = rootfa[ver-1];
        rootdep[ver] = rootdep[ver-1];
    }
    else 
    {
        int depx = query(1,n,rootdep[ver-1],x);
        int depy = query(1,n,rootdep[ver-1],y);
        if(depx<depy)
        {
            modify(1,n,rootfa[ver-1],rootfa[ver],x,y);
            rootdep[ver] = rootdep[ver-1];
        }
        else if(depx>depy)
        {
            modify(1,n,rootfa[ver-1],rootfa[ver],y,x);
            rootdep[ver] = rootdep[ver-1];
        }
        else 
        {
            modify(1,n,rootfa[ver-1],rootfa[ver],x,y);
            modify(1,n,rootdep[ver-1],rootdep[ver],y,depy+1);
        }
    }
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int m;
    cin>>n>>m;
    build(1,n,rootfa[0]);
    for(int ver=1;ver<=m;ver++)
    {
        int opt,x,y;
        cin>>opt>>x;
        if(opt==1)
        {
            cin>>y;
            merge(ver,x,y);
        }
        else if(opt==2)
        {
            rootfa[ver] = rootfa[x];
            rootdep[ver] = rootdep[x];
        }
        else
        {
            cin>>y;
            rootfa[ver] = rootfa[ver-1];
            rootdep[ver] = rootdep[ver-1];
            int fx = find(ver,x);
            int fy = find(ver,y);
            cout<<(fx==fy)<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}