#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/debug.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
const int mod = 998244353;
constexpr ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
constexpr ll inv(ll x) { return qpow(x,mod-2,mod); }
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        ll g = count(v.begin(), v.end(), 0);
        ll o = count(v.begin(), v.begin()+g, 0);
        vector<ll> dp(g+1);
        for(ll i=g-1;i>=o;i--)
        {
            auto p = 2*(g-i)%mod*(g-i)%mod*inv(n*(n-1)%mod)%mod;
            dp[i] = (dp[i+1]*p+1)%mod*inv(p)%mod;
        }
        cout<<dp[o]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
