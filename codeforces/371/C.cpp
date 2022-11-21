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
    string s;
    cin>>s;
    const string_view _b = "BSC";
    vector<ll> ned(3), cnt(3), pri(3);
    for(int i=0;i<3;i++) ned[i] = count(s.begin(), s.end(), _b[i]);
    for(int i=0;i<3;i++) cin>>cnt[i];
    for(int i=0;i<3;i++) cin>>pri[i];
    ll w;
    cin>>w;
    auto check = [&](const ll g)
    {
        ll p = 0;
        for(int i=0;i<3;i++) p += (max(0LL, g*ned[i]-cnt[i]))*pri[i];
        return p<=w;
    };
    ll l=0, r=w+100;
    while(l<r)
    {
        ll m = midpoint(l, r)+1;
        if(check(m)) l = m;
        else r = m-1;
    }
    cout<<l<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
