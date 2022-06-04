#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 2e5+5;
typedef long long ll;
ll a[maxn];
struct Node
{
    int l,r;
    ll val,f;
}sgt[maxn<<2];
int ls(int k) { return k<<1; };
int rs(int k) { return k<<1|1; }
inline void pushup(int k) { sgt[k].val = sgt[ls(k)].val+sgt[rs(k)].val; }
inline void pushdw(int k)
{
    ll f = sgt[k].f;
    sgt[k].f = 0;
    sgt[ls(k)].f = f;
    sgt[rs(k)].f = f;
    sgt[ls(k)].val = (sgt[ls(k)].r-sgt[ls(k)].l+1)*f;
    sgt[rs(k)].val = (sgt[rs(k)].r-sgt[rs(k)].l+1)*f;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r)
    {
        sgt[k].val = a[l];
        return;
    }
    int m = (l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
    pushup(k);
}
void modify(int x,int y,ll z,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f = z;
        sgt[k].val = (r-l+1)*z;
        return;
    }
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) modify(x,y,z,ls(k));
    if(y>m) modify(x,y,z,rs(k));
    pushup(k);
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n);
    while(m--)
    {
        int opt,x,y;
        cin>>opt>>x;
        if(opt==1)
        {
            cin>>y;
            modify(x,x,y);
        }
        else modify(1,n,x);
        cout<<sgt[1].val<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}