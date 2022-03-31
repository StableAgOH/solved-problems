#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e6+5;
const int mod = 10007;
typedef long long ll;
ll fac[mod+5];
ll qpow(ll a, ll k)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%mod)
        if(k&1) res=res*a%mod;
    return res;
}
ll C(ll n, ll m)
{
    return n>=m?fac[n]*qpow(fac[m], mod-2)%mod*qpow(fac[n-m], mod-2)%mod:0;
}
ll lucas(ll n, ll m)
{
    return m?lucas(n/mod, m/mod)*C(n%mod, m%mod)%mod:1;
}
int a[maxn];
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
    fac[0]=1;
    for(int i=1;i<mod;i++) fac[i]=fac[i-1]*i%mod;
    int n;
    cin>>n;
    int x=n, l=n/2, r=n/2+1;
    if(n%2) a[r++]=x--;
    while(x) a[l--]=x--, a[r++]=x--;
    ll sum = 0;
    for(int i=0;i<n;i++)
        sum = (sum + lucas(n-1, i)*a[i+1])%mod;
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
