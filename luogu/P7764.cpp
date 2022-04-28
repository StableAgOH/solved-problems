#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
#include <vector>
#include <algorithm>
const int maxn = 5e5+5;
int a[maxn], cnt[maxn], pos[maxn];
int ans[maxn];
int tot;
void add(int p)
{
    cnt[a[p]]++;
    if(cnt[a[p]]==2) tot++;
    else if(cnt[a[p]]==3) tot--;
}
void sub(int p)
{
    cnt[a[p]]--;
    if(cnt[a[p]]==2) tot++;
    else if(cnt[a[p]]==1) tot--;
}
struct Q { int l,r,k; } q[maxn];
vector<int> v;
inline int getid(int x) { return lower_bound(v.begin(), v.end(), x)-v.begin()+1; }
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
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
        v.push_back(a[i]);
        pos[i] = i/siz;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=1;i<=n;i++) a[i] = getid(a[i]);
    for(int i=0;i<m;i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].k = i;
    }
    sort(q, q+m, [](Q& a,Q& b) { return pos[a.l]==pos[b.l]?a.r<b.r:pos[a.l]<pos[b.l]; });
    int l=1, r=0;
    for(int i=0;i<m;i++)
    {
        while(l<q[i].l) sub(l++);
        while(l>q[i].l) add(--l);
        while(r<q[i].r) add(++r);
        while(r>q[i].r) sub(r--);
        ans[q[i].k] = tot;
    }
    for(int i=0;i<m;i++) cout<<ans[i]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}