#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 2e5 + 5;
typedef long long ll;
struct Node
{
    int l,r;
    ll f,val;
}sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k) { sgt[k].val = sgt[ls(k)].val + sgt[rs(k)].val; }
inline void pushdw(int k)
{
    ll f = sgt[k].f; sgt[k].f = 0;
    sgt[ls(k)].f+=f; sgt[rs(k)].f+=f;
    sgt[ls(k)].val+=(sgt[ls(k)].r-sgt[ls(k)].l+1)*f;
    sgt[rs(k)].val+=(sgt[rs(k)].r-sgt[rs(k)].l+1)*f;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r) return;
    int m = (l+r)>>1;
    build(l, m, ls(k));
    build(m+1, r, rs(k));
}
void modify(int x,int y,ll z,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f+=z;
        sgt[k].val+=(r-l+1)*z;
        return;
    }
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) modify(x,y,z,ls(k));
    if(y>m) modify(x,y,z,rs(k));
    pushup(k);
}
ll query(int x,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(l==r) return sgt[k].val;
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) return query(x, ls(k));
    else return query(x, rs(k));
}
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
    int n,k;
    cin>>n>>k;
    build(1,maxn);
    int mn = 0x3f3f3f3f;
    int mx = 0xcfcfcfcf;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mn = min(mn, x);
        mx = max(mx, x);
        if(x) modify(1, x, 1);
    }
    ll ans = 0, tot=0;
    for(int i=mx;i>mn;i--)
    {
        ll tmp = query(i);
        tot += tmp;
        if(tot > k)
        {
            ans++;
            tot = tmp;
        }
    }
    if(tot) ans++;
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}