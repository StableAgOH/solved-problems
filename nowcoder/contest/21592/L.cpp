#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
typedef long long ll;
const int maxn = 1e5+5;
vector<int> v;
struct Node
{
    int l,r;
    int cover;
    ll len;
}sgt[maxn<<3];
inline int ls(int k) { return k<<1; }
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k)
{
    if(sgt[k].cover) sgt[k].len=sgt[k].r-sgt[k].l;
    else sgt[k].len=sgt[ls(k)].len+sgt[rs(k)].len;
}
void build(int l,int r,int k=1)
{
    sgt[k].l=v[l], sgt[k].r=v[r];
    if(r-l<=1) return;
    int m=(l+r)>>1;
    build(l,m,ls(k));
    build(m,r,rs(k));
}
void modify(int x,int y,int z=1,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r)
    {
        sgt[k].cover+=z;
        pushup(k);
        return;
    }
    if(x<sgt[ls(k)].r) modify(x,y,z,ls(k));
    if(y>sgt[rs(k)].l) modify(x,y,z,rs(k));
    pushup(k);
}
vector<pair<int,int>> q;
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        v.insert(v.end(), {x1,x2});
        q.emplace_back(x1,x2);
    }
    v.push_back(-1);
    sort(v.begin(),v.end());
    build(1, v.size()-1);
    for(auto it=q.begin();it!=q.end();it++)
        modify(it->first, it->second);
    cout<<sgt[1].len<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
