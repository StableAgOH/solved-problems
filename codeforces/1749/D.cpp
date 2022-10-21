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
const int maxn = 3e5+5;
const int mod = 998244353;
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
bool vis[maxn];
vector<int> pri;
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
    ll n,m;
    cin>>n>>m;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]) pri.push_back(i);
        for(auto j : pri)
        {
            if(ll(i)*j>n) break;
            vis[i*j] = true;
            if(i%j==0) break;
        }
    }
    ll pre = 1;
    ll mul = 1;
    ll sum = 0;
    auto it = pri.begin();
    for(int i=1;i<=n;i++)
    {
        if(i==*it)
        {
            pre *= *it;
            if(pre>m) break;
            ++it;
        }
        mul = mul*((m/pre)%mod)%mod;
        sum = (sum+mul)%mod;
    }
    ll S = 0;
    for(int i=1;i<=n;i++) S = (S+qpow(m%mod,i,mod))%mod;
    cout<<(S-sum+mod)%mod<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
