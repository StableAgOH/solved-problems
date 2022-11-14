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
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    __red(argc, argv);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int e = ceil(sqrt(2e12));
    vector<int> pri;
    vector<bool> vis(e+1);
    for(int i=2;i<=e;i++)
    {
        if(!vis[i]) pri.push_back(i);
        for(int j : pri)
        {
            if(ll(i)*j>e) break;
            vis[i*j] = true;
            if(i%j==0) break;
        }
    }
    debug(pri.size());
    auto fac = [&](ll x)
    {
        vector<ll> v;
        for(int j : pri)
        {
            if(x%j==0) v.push_back(j);
            while(x%j==0) x /= j;
        }
        if(x!=1) v.push_back(x);
        return v;
    };
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        auto f = fac(a+b);
        auto g = fac(a);
        auto h = fac(b);
        vector<ll> u;
        set_intersection(g.begin(), g.end(), h.begin(), h.end(), back_inserter(u));
        vector<ll> v;
        set_intersection(f.begin(), f.end(), u.begin(), u.end(), back_inserter(v));
        ll x = f.size();
        ll y = g.size();
        ll z = h.size();
        ll w = v.size();
        cout<<x-w+y*z<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
