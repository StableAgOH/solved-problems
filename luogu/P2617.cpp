#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
//==========================================
const int maxn = 1e5+5;
vector<int> o;
int getid(int x) { return lower_bound(o.begin(), o.end(), x)-o.begin()+1; };
struct Node { int l,r,val; } sgt[maxn*400];
int cnt, root[maxn];
int& ls(int k) { return sgt[k].l; }
int& rs(int k) { return sgt[k].r; }
void modify(int l,int r,int p,int x,int& k)
{
    if(!k) k = ++cnt;
    sgt[k].val += x;
    if(l==r) return;
    int m = (l+r)>>1;
    if(p<=m) modify(l,m,p,x,ls(k));
    else modify(m+1,r,p,x,rs(k));
}
int query(int l,int r,vector<int>& L,vector<int>& R,int k)
{
    if(l==r) return l;
    int m = (l+r)>>1;
    int sum = 0;
    for(auto i : R) sum += sgt[ls(i)].val;
    for(auto i : L) sum -= sgt[ls(i)].val;
    if(k<=sum)
    {
        transform(L.begin(), L.end(), L.begin(), ls);
        transform(R.begin(), R.end(), R.begin(), ls);
        return query(l,m,L,R,k);
    }
    else
    {
        transform(L.begin(), L.end(), L.begin(), rs);
        transform(R.begin(), R.end(), R.begin(), rs);
        return query(m+1,r,L,R,k-sum);
    }
}
int n;
int lowbit(int x) { return x&-x; }
void modify(int p,int q,int x)
{
    for(int i=p;i<=n;i+=lowbit(i)) modify(1,o.size(),q,x,root[i]);
}
int query(int l,int r,int k)
{
    vector<int> L,R;
    for(int i=r;i;i-=lowbit(i)) R.push_back(root[i]);
    for(int i=l-1;i;i-=lowbit(i)) L.push_back(root[i]);
    return query(1,o.size(),L,R,k);
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
#endif
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int m;
    cin>>n>>m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    o.insert(o.end(), v.begin()+1, v.end());
    vector<tuple<int,int,int>> w;
    for(int i=0;i<m;i++)
    {
        char opt;
        cin>>opt;
        if(opt=='Q')
        {
            int l,r,k;
            cin>>l>>r>>k;
            w.emplace_back(l,r,k);
        }
        else
        {
            int p,x;
            cin>>p>>x;
            w.emplace_back(p,x,-1);
            o.push_back(x);
        }
    }
    sort(o.begin(), o.end());
    o.erase(unique(o.begin(), o.end()), o.end());
    for(int i=1;i<=n;i++) modify(i, getid(v[i]), 1);
    for(auto [x,y,z] : w)
    {
        if(~z) cout<<o[query(x,y,z)-1]<<'\n';
        else
        {
            modify(x, getid(v[x]), -1);
            v[x] = y;
            modify(x, getid(v[x]), 1);
        }
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
