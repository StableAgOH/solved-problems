#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
typedef long long ll;
ll a[maxn], b[maxn];
struct Node
{
    int l,r;
    ll f,val,cnt;
    bool exist;
} sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k)
{
    sgt[k].val = sgt[ls(k)].val+sgt[rs(k)].val;
    sgt[k].cnt = sgt[ls(k)].cnt+sgt[rs(k)].cnt;
}
inline void pushdw(int k)
{
    ll f = sgt[k].f; sgt[k].f = 0;
    sgt[ls(k)].f += f;
    sgt[rs(k)].f += f;
    sgt[ls(k)].val += sgt[ls(k)].cnt * f;
    sgt[rs(k)].val += sgt[rs(k)].cnt * f;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r)
    {
        sgt[k].val = a[l];
        sgt[k].exist = b[l];
        if(b[l])
        {
            sgt[k].val = a[l];
            sgt[k].cnt = 1;
        }
        return;
    }
    int m = (l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
    pushup(k);
}
void modify(int p,bool z,int k)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(l==r)
    {
        if(sgt[k].exist&&!z) sgt[k].cnt--;
        else if(!sgt[k].exist&&z) sgt[k].cnt++;
        sgt[k].exist = z;
        return;
    }
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    if(p<=m) modify(p,z,ls(k));
    else modify(p,z,rs(k));
    pushup(k);
}
void modify(int x,int y,int z,int k)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f += z;
        sgt[k].val += sgt[k].cnt * z;
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
    if(x<=l&&y>=r) return sgt[k].val;
    if(sgt[k].f) pushdw(k);
    int m = (l+r)>>1;
    ll sum = 0;
    if(x<=m) sum += query(x,y,ls(k));
    if(y>m) sum += query(x,y,rs(k));
    return sum;
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
    for(int i=1;i<=n;i++) cin>>b[i];
    build(1,n);
    cerr<<sgt[1].cnt<<endl;
    while(m--)
    {
        int opt,x,y,z;
        cin>>opt;
        switch(opt)
        {
        case 1:
            cin>>x;
            modify(x,false,1);
            break;
        case 2:
            cin>>x;
            modify(x,true,1);
            break;
        case 3:
            cin>>x>>y>>z;
            modify(x,y,z,1);
            break;
        case 4:
            cin>>x>>y;
            cout<<query(x,y)<<'\n';
            break;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}