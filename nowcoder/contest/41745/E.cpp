#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <numeric>
#include <algorithm>
const int maxn = 1e5+5;
typedef long long ll;
ll a[maxn];
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    ll mx = 0;
    for(int i=1;i<=n;i++)
    {
        ll x,y;
        cin>>x>>y;
        mx = max(mx, y);
        a[i] = x-y;
    }
    ll g = a[1];
    for(int i=2;i<=n;i++) g = gcd(g, a[i]);
    vector<ll> v;
    for(ll i=1;i*i<=g;i++)
    {
        if(g%i) continue;
        if(i>mx) v.push_back(i);
        ll t = g/i;
        if(t>mx&&t!=i) v.push_back(t);
    }
    sort(v.begin(), v.end());
    cout<<v.size()<<'\n';
    for(auto i : v) cout<<i<<'\n';
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
