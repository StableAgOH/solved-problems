#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
#include <cmath>
#include <algorithm>
const int maxn = 1e5+5;
const int mod = 1e9+7;
typedef long long ll;
struct Q
{
    int l,r,k;
}q[maxn];
int pos[maxn],ans[maxn];
string s;
int one,zero;
void add(int n)
{
    if(s[n]=='1') one++;
}
void sub(int n)
{
    if(s[n]=='1') one--;
}
ll qpow(ll a, ll k)
{
    ll res=1;
    for(;k;k>>=1,a=a*a%mod)
        if(k&1) res=res*a%mod;
    return res;
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
    int n,m;
    cin>>n>>m>>s;
    int siz = sqrt(n);
    for(int i=1;i<=n;i++)
        pos[i]=i/siz;
    for(int i=0;i<m;i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].l--, q[i].r--;
        q[i].k=i;
    }
    sort(q, q+m, [](Q x, Q y){
        return pos[x.l]==pos[y.l]?x.r<y.r:pos[x.l]<pos[y.l];
    });
    int l=1,r=0;
    for(int i=0;i<m;i++)
    {
        while(q[i].l<l) add(--l);
        while(q[i].r>r) add(++r);
        while(q[i].l>l) sub(l++);
        while(q[i].r<r) sub(r--);
        ans[q[i].k]=qpow(2, q[i].r-q[i].l+1-one)*(qpow(2, one)-1)%mod;
    }
    for(int i=0;i<m;i++)
        cout<<ans[i]<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}