#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 2e5+5;
const int mod = 1e9+7;
typedef long long ll;
ll fac[maxn];
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
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
    fac[0]=1;
    for(int i=1;i<=2e5;i++)
        fac[i]=fac[i-1]*i%mod;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,k,q;
        cin>>n>>m>>k>>q;
        if(k>n) cout<<0<<'\n';
        else 
        {
            ll a = qpow(fac[n]*fac[n+m-k]%mod, q, mod);
            ll b = qpow(fac[n+m]*fac[n-k]%mod, q, mod);
            cout<<a*qpow(b,mod-2,mod)%mod<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
