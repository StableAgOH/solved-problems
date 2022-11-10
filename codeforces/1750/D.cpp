#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
const int mod = 998244353;
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
const int maxn = 1e5+5;
bool vis[maxn];
vector<ll> pri;
auto fac(ll x)
{
    unordered_map<ll,ll> mp;
    for(auto i : pri)
    {
        while(x%i==0)
        {
            x /= i;
            mp[i]++;
        }
    }
    if(x!=1) mp[x]++;
    return mp;
}
ll h = 0;
ll s = 0;
void dfs(const vector<ll>& v, size_t i, int x, ll mul=1)
{
    if(!x)
    {
        s = (s+h/mul)%mod;
        return;
    }
    if(i==v.size()) return;
    for(size_t j=i;j<v.size();j++)
        dfs(v, j+1, x-1, mul*v[j]);
};
ll g(const vector<ll>& v, ll k)
{
    h = k;
    ll sum = k;
    for(size_t j=1;j<=v.size();j++)
    {
        s = 0;
        dfs(v, 0, j);
        if(j&1) sum = (sum-s+mod)%mod;
        else sum = (sum+s)%mod;
    }
    return sum;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    __red(argc, argv);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int _n = 1e5;
    for(int i=2;i<=_n;i++)
    {
        if(!vis[i]) pri.push_back(i);
        for(auto j : pri)
        {
            if((ll)i*j>_n) break;
            vis[i*j] = true;
            if(i%j==0) break;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        auto it = find(v.begin()+1, v.end(), 1);
        if(it!=v.end()&&!all_of(it, v.end(), [](int x) { return x==1; }))
        {
            cout<<0<<'\n';
            continue;
        }
        if(v[1]==1)
        {
            cout<<qpow(m, n-1, mod)<<'\n';
            continue;
        }
        ll ans = 1;
        auto lst = fac(v[1]);
        for(int i=2;i<=n;i++)
        {
            if(v[i-1]%v[i])
            {
                ans = 0;
                break;
            }
            if(v[i]==1)
            {
                vector<ll> w;
                for(auto [k,v] : lst) if(v) w.push_back(k);
                auto p = g(w, m);
                ans = ans*p%mod;
                ans = ans*qpow(m, n-i, mod)%mod;
                break;
            }
            else if(v[i-1]==v[i]) ans = ans*(m/v[i])%mod;
            else
            {
                auto f = fac(v[i]);
                vector<ll> w;
                for(auto [k,v] : lst) if(f[k]!=v) w.push_back(k);
                auto k = m/v[i];
                auto p = g(w, k);
                ans = ans*p%mod;
                lst = f;
            }
        }
        cout<<ans<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
