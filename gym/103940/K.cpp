#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
const int mod = 1e9+7;
typedef long long ll;
ll a[maxn];
struct Node
{
    int l,r;
    ll f,val1,val2;
}sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline int sz(int k) { return sgt[k].r-sgt[k].l+1; }
inline void pushup(int k)
{
    sgt[k].val1 = (sgt[ls(k)].val1+sgt[rs(k)].val1)%mod;
    sgt[k].val2 = (sgt[ls(k)].val2+sgt[rs(k)].val2)%mod;
}
inline void pushdw(int k)
{
    ll f = sgt[k].f;
    sgt[k].f = 0;
    sgt[ls(k)].f = (sgt[ls(k)].f+f)%mod;
    sgt[rs(k)].f = (sgt[rs(k)].f+f)%mod;
    sgt[ls(k)].val2 = (sgt[ls(k)].val2+sz(ls(k))*f%mod*f%mod+2*f%mod*sgt[ls(k)].val1%mod)%mod;
    sgt[rs(k)].val2 = (sgt[rs(k)].val2+sz(rs(k))*f%mod*f%mod+2*f%mod*sgt[rs(k)].val1%mod)%mod;
    sgt[ls(k)].val1 = (sgt[ls(k)].val1+sz(ls(k))*f%mod)%mod;
    sgt[rs(k)].val1 = (sgt[rs(k)].val1+sz(rs(k))*f%mod)%mod;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r)
    {
        sgt[k].val1 = a[l];
        sgt[k].val2 = a[l]*a[l]%mod;
        return;
    }
    int m = (l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
    pushup(k);
}
void modify(int x,int y,ll z,int k=1)
{
    if(z<0) z += mod;
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f = (sgt[k].f+z)%mod;
        sgt[k].val2 = (sgt[k].val2+sz(k)*z%mod*z%mod+2*z%mod*sgt[k].val1%mod)%mod;
        sgt[k].val1 = (sgt[k].val1+sz(k)*z%mod)%mod;
        return;
    }
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    if(x<=m) modify(x,y,z,ls(k));
    if(y>m) modify(x,y,z,rs(k));
    pushup(k);
}
ll query(int x,int y,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].val2;
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    ll sum = 0;
    if(x<=m) sum = query(x,y,ls(k));
    if(y>m) sum = (sum+query(x,y,rs(k)))%mod;
    return sum;
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n);
    while(m--)
    {
        char opt;
        cin>>opt;
        if(opt=='u')
        {
            int x,y;
            ll z;
            cin>>x>>y>>z;
            modify(x,y,z);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            cout<<query(x,y)<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
