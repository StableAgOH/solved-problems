#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 2e7+5;
const int mod = 1e9+7;
typedef long long ll;
ll fac[maxn];
ll qpow(ll a,ll k)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%mod)
        if(k&1) res = res*a%mod;
    return res;
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
    fac[0] = 1;
    for(int i=1;i<=2e7;i++) fac[i] = fac[i-1]*i%mod;
    int n,m;
    cin>>n>>m;
    n = n+m-1;
    cout<<fac[n]*qpow(fac[m]*fac[n-m]%mod,mod-2)%mod<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
