#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
const int maxn = 2e6+5;
const int mod = 998244353;
typedef long long ll;
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
ll fac[maxn]={1}, inv[maxn]={1};
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
    const int p = 2e6;
    for(int i=1;i<=p;i++)
    {
        fac[i] = fac[i-1]*i%mod;
        inv[i] = qpow(fac[i], mod-2, mod);
    }
    int a,b;
    cin>>a;
    a = ceil(a/10.0);
    for(int i=0,x;i<7;i++) cin>>x;
    cin>>b;
    b = ceil(b/10.0);
    for(int i=0,x;i<7;i++) cin>>x;
    ll sum = 0;
    for(int i=0;i<a;i++) sum = (sum+fac[i+b-1]*inv[i]%mod*inv[b-1]%mod*qpow(qpow(2,b+i,mod),mod-2,mod)%mod)%mod;
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
