#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
const int maxn = 65;
const int mod = 998244353;
typedef long long ll;
ll fac[maxn]={1}, inv[maxn]={1};
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
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
    for(int i=1;i<=60;i++)
    {
        fac[i] = fac[i-1]*i%mod;
        inv[i] = qpow(fac[i],mod-2,mod);
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll sum = 0;
        for(int i=n/2-2;i>=0;i-=2)
        {
            int t = i*2+2;
            sum = (sum+fac[t]*inv[i]%mod*inv[t-i]%mod)%mod;
            sum = (sum+fac[t-1]*inv[i]%mod*inv[t-1-i]%mod)%mod;
        }
        ll x = fac[n]*inv[n/2]%mod*inv[n/2]%mod;
        cout<<(x-sum+mod-1)%mod<<' '<<sum<<' '<<1<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
