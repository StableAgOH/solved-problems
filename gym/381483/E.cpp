#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
const int maxn = 1e5+5;
typedef long long ll;
ll a[maxn];
vector<ll> v;
inline int getid(ll x) { return lower_bound(v.begin(),v.end(),x)-v.begin()+1; }
struct Node { int l,r,cnt; ll val; } hjt[maxn*20];
int cnt, root[maxn];
void modify(int l,int r,int pre,int& k,int p)
{
    hjt[k=++cnt] = hjt[pre];
    hjt[k].cnt++;
    hjt[k].val += v[p-1];
    if(l==r) return;
    int m = (l+r)>>1;
    if(p<=m) modify(l,m,hjt[pre].l,hjt[k].l,p);
    else modify(m+1,r,hjt[pre].r,hjt[k].r,p);
}
ll query(int l,int r,int L,int R,int k)
{
    if(l==r)
    {
        int c = hjt[R].cnt-hjt[L].cnt;
        if(!c) return 0;
        int s = hjt[R].val-hjt[L].val;
        return s/c*k;
    }
    int t = hjt[hjt[R].l].cnt-hjt[hjt[L].l].cnt;
    int m = (l+r)>>1;
    if(k<=t) return query(l,m,hjt[L].l,hjt[R].l,k);
    else return hjt[hjt[R].l].val-hjt[hjt[L].l].val+query(m+1,r,hjt[L].r,hjt[R].r,k-t);
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
    int mid = (1+n)>>1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++) modify(1,n,root[i-1],root[i],getid(a[i]));
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int m = (r-l+1)>>1;
        ll y = hjt[root[r]].val-hjt[root[l-1]].val;
        ll x = query(1,n,root[l-1],root[r],m);
        cout<<y-x-x<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
