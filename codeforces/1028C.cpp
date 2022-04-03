#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
const int maxn = 3e5+5;
struct L
{
    int x,y1,y2,state;
    bool operator<(L l) const { 
        if(x<l.x) return true;
        else if(x==l.x) return state>l.state;
        else return false;
     }
};
vector<L> v;
struct Node
{
    int l,r,f,val;
}sgt[maxn<<2];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k) { sgt[k].val=max(sgt[ls(k)].val,sgt[rs(k)].val); }
inline void pushdw(int k)
{
    int f=sgt[k].f; sgt[k].f=0;
    sgt[ls(k)].f+=f, sgt[rs(k)].f+=f;
    sgt[ls(k)].val+=f, sgt[rs(k)].val+=f;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r) return;
    int m=(l+r)>>1;
    build(l,m,ls(k));
    build(m+1,r,rs(k));
}
void modify(int x,int y,int z,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].f+=z;
        sgt[k].val+=z;
        return;
    }
    if(sgt[k].f) pushdw(k);
    int m=(l+r)>>1;
    if(x<=m) modify(x,y,z,ls(k));
    if(y>m) modify(x,y,z,rs(k));
    pushup(k);
}
int query(int x,int k=1)
{
    if(sgt[k].val!=x) return -1;
    int l=sgt[k].l, r=sgt[k].r;
    if(l==r) return l;
    if(sgt[k].f) pushdw(k);
    if(sgt[ls(k)].val==x) return query(x, ls(k));
    else return query(x, rs(k));
}
vector<int> _v;
int getid(int x) { return lower_bound(_v.begin(), _v.end(), x)-_v.begin()+1; }
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        v.push_back((L){x1, y1, y2, 1});
        v.push_back((L){x2, y1, y2, -1});
        _v.push_back(y1);
        _v.push_back(y2);
    }
    sort(v.begin(), v.end());
    sort(_v.begin(), _v.end());
    _v.erase(unique(_v.begin(),_v.end()),_v.end());
    build(1, _v.size());
    for(auto i : v)
    {
        modify(getid(i.y1), getid(i.y2), i.state);
        int pos = query(n-1); 
        if(~pos) { cout<<i.x<<' '<<_v[pos-1]<<endl; break; }
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}