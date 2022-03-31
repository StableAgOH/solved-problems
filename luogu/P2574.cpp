#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 2e5+5;
int v[maxn];
struct Node
{
    int l,r,f,val;
}sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k) { sgt[k].val=sgt[ls(k)].val+sgt[rs(k)].val; }
inline void pushdw(int k)
{
    sgt[k].f=0;
    sgt[ls(k)].f^=1, sgt[rs(k)].f^=1;
    sgt[ls(k)].val=sgt[ls(k)].r-sgt[ls(k)].l+1-sgt[ls(k)].val;
    sgt[rs(k)].val=sgt[rs(k)].r-sgt[rs(k)].l+1-sgt[rs(k)].val;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r)
    {
        sgt[k].val=v[l];
        return;
    }
    int m = (l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
    pushup(k);
}
void modify(int x,int y,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f^=1;
        sgt[k].val = r-l+1-sgt[k].val;
        return;
    }
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) modify(x,y,ls(k));
    if(y>m) modify(x,y,rs(k));
    pushup(k);
}
int query(int x,int y,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].val;
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    int sum = 0;
    if(x<=m) sum = query(x,y,ls(k));
    if(y>m) sum += query(x,y,rs(k));
    return sum;
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
    int n,m;
    cin>>n>>m;
    char c;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        v[i]=c-'0';
    }
    build(1,n);
    while(m--)
    {
        int opt,l,r;
        cin>>opt>>l>>r;
        if(opt) cout<<query(l,r)<<endl;
        else modify(l,r);
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}