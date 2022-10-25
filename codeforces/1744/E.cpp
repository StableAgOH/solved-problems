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
auto factor(ll x)
{
    map<ll,ll> mp;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i) continue;
        int cnt = 0;
        while(x%i==0)
        {
            x /= i;
            cnt++;
        }
        mp[i] = cnt;
    }
    if(x>1) mp[x] = 1;
    return mp;
}
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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        auto f=factor(a), g=factor(b);
        for(auto&& [k,v] : g) f[k] += v;
        vector fac(f.begin(), f.end());
        debug(fac);
        function<bool(size_t,ll,ll)> dfs = [&](size_t p,ll x,ll y) {
            if(x>c||y>d) return false;
            if(p==fac.size())
            {
                auto u = (a/x+1)*x;
                auto v = (b/y+1)*y;
                if(u>a&&u<=c&&v>b&&v<=d)
                {
                    cout<<u<<' '<<v<<'\n';
                    return true;
                }
                return false;
            }
            auto&& [k,v] = fac[p];
            int cnt = 0;
            y *= powl(k,v);
            while(true)
            {
                if(dfs(p+1, x, y)) return true;
                cnt++;
                if(cnt>v) break;
                x *= k;
                y /= k;
            }
            return false;
        };
        if(!dfs(0,1,1)) cout<<-1<<' '<<-1<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
