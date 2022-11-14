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
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,l,r;
        cin>>a>>b>>c>>l>>r;
        auto f = [&](ll x) { return a*x*x+b*x+c; };
        vector<ll> v;
        auto ins = [&](ll x) { if(x>=l&&x<=r) v.push_back(f(x)); };
        ins(l); ins(r);
        if(a)
        {
            ll p = (-b)/(2*a);
            ins(p-1); ins(p); ins(p+1);
        }
        debug(v);
        cout<<*min_element(v.begin(), v.end())<<' ';
        cout<<*max_element(v.begin(), v.end())<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
