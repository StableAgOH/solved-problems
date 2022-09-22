#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
#include <algorithm>
#include <unordered_map>
const int maxn = 2e5+5;
const int maxx = 2e6+5;
typedef long long ll;
ll a[maxn], pos[maxn], pre[maxn];
struct Q { ll l,r,k; } q[maxn];
ll res, ans[maxn];
ll cnt[maxx][2];
void add(int p)
{
    res += cnt[pre[p]][p%2];
    cnt[pre[p]][p%2]++;
}
void sub(int p)
{
    cnt[pre[p]][p%2]--;
    res -= cnt[pre[p]][p%2];
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
    int siz = sqrt(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pos[i] = i/siz;
    }
    for(int i=1;i<=n;i++) pre[i] = pre[i-1]^(a[i]-1);
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        q[i] = {l-1,r,i};
    }
    sort(q, q+m, [](Q& x,Q& y) {
        return pos[x.l]==pos[y.l]?x.r<y.r:pos[x.l]<pos[y.l];
    });
    int l=0, r=-1;
    for(int i=0;i<m;i++)
    {
        while(q[i].l<l) add(--l);
        while(q[i].r>r) add(++r);
        while(q[i].l>l) sub(l++);
        while(q[i].r<r) sub(r--);
        ll t = r-l;
        ans[q[i].k] = t*(t+1)/2 - res;
    }
    for(int i=0;i<m;i++) cout<<ans[i]<<'\n';
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
