#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
typedef long long ll;
ll n;
int trans(ll x,ll y)
{
    ll l=x, r=x;
    for(ll i=0;;i++,l*=10,r=r*10+9)
    {
        ll t = y+(int)ceil(1.0*(l-y)/n)*n;
        if(l<=t&&t<=r) return i;
    }
}
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
    cin>>n;
    ll cnt = 0;
    for(ll i=0;i<n;i++) cnt += trans(i, (i+1)%n);
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
