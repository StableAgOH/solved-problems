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
const int maxn = 5e4+5;
const int mod = 998244353;
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
ll inv(ll x) { return qpow(x,mod-2,mod); }
ll C(ll n,ll m)
{
    ll mul = 1;
    m = max(m, n-m);
    for(ll i=n;i>m;i--) mul = mul*i%mod*inv(n-i+1)%mod;
    return mul;
}
ll a[maxn];
unordered_map<ll,ll> mp;
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    ll k = *max_element(a+1, a+1+n);
    for(int i=1;i<k;i++) cout<<0<<'\n';
    ll f = 1;
    for(auto&& [x,y] : mp) f = f*qpow(C(k,x),y,mod)%mod;
    for(int i=k;i<=m;i++)
    {
        cout<<f<<'\n';
        for(auto&& [x,y] : mp) f = f*qpow((i+1)*inv(i+1-x)%mod,y,mod)%mod;
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
