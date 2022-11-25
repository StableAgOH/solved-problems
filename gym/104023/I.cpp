#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
//==========================================
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
#endif
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<ll> a(n), b(k);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<k;i++) cin>>b[i];
        ll l=0, r=0;
        for(int i=0;i<k;i++) r += b[i]*(1<<i);
        auto check = [&](ll m)
        {
            vector<__int128_t> c(n);
            for(int i=0;i<n;i++) c[i] = __int128_t(a[i])*m;
            for(int i=k-1;i>=0;i--)
            {
                __int128_t q = b[i];
                ll o = 1<<i;
                for(int j=0;j<n;j++)
                {
                    if(!b[i]) break;
                    auto d = min(q, c[j]/o);
                    q -= d;
                    c[j] -= o*d;
                }
                auto ik = q>=n?c.end():c.begin()+int(q);
                nth_element(c.begin(), ik, c.end(), greater<>());
                fill(c.begin(), ik, 0);
            }
            return all_of(c.begin(), c.end(), [](auto x) { return x==0; });
        };
        while(l<r)
        {
            ll m = midpoint(l,r)+1;
            if(check(m)) l = m;
            else r = m-1;
        }
        cout<<l<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
