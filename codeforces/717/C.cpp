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
struct hasher
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x^(x>>30))*0xbf58476d1ce4e5b9;
        x = (x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const 
    {
        static const uint64_t fix = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+fix);
    }
};
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
    const int mod = 10007;
    int n;
    cin>>n;
    vector<ll> v(n), w(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());
    reverse_copy(v.begin(), v.end(), w.begin());
    ll sum = 0;
    for(int i=0;i<n;i++) sum = (sum+v[i]*w[i])%mod;
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
