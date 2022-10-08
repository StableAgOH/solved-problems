#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
typedef long long ll;
ll pre(ll x)
{
    ll s = sqrtl(x);
    ll ret = s*3-2;
    if(x>=s*s+s) ret++;
    if(x>=s*s+s+s) ret++;
    return ret;
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
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<pre(r)-pre(l-1)<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
