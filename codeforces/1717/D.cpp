#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
const int maxn = 1e5+5;
const int mod = 1e9+7;
typedef long long ll;
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
ll inv(ll x) { return qpow(x,mod-2,mod); }
ll fac[maxn];
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
    ll n,k;
    cin>>n>>k;
    if(k>=n) cout<<qpow(2,n,mod)<<endl;
    else
    {
        fac[0] = 1;
        for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
        ll sum = 0;
        for(int i=0;i<=k;i++) sum = (sum+fac[n]*inv(fac[i])%mod*inv(fac[n-i]))%mod;
        cout<<sum<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
