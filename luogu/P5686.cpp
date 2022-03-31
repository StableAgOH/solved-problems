#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 5e5+5;
const int mod = 1e9+7;
typedef long long ll;
ll a[maxn],b[maxn];
ll prea[maxn],preb[maxn],preab[maxn];
ll preprea[maxn],prepreb[maxn],prepreab[maxn];
int n;
inline void calcPre(ll a[], ll pre[])
{
    for(int i=1;i<=n;i++)
        pre[i]=(a[i]+pre[i-1]) % mod;
}
ll solve()
{
    ll sum = 0;
    for(int l=1;l<=n;l++)
    {
        sum = (sum + prepreab[n]-prepreab[l-1]+mod) % mod;
        sum = (sum + (n-l+1)*preab[l-1]%mod) % mod;
        sum -= (preprea[n]-preprea[l-1])*preb[l-1]%mod;
        sum = (sum + mod) % mod;
        sum -= (prepreb[n]-prepreb[l-1])*prea[l-1]%mod;
        sum = (sum + mod) % mod;
    }
    return sum;
}
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
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    calcPre(a, prea);
    calcPre(b, preb);
    for(int i=1;i<=n;i++) preab[i]=prea[i]*preb[i]%mod;
    calcPre(prea, preprea);
    calcPre(preb, prepreb);
    calcPre(preab, prepreab);
    cout<<solve()<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
