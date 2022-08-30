#include <iostream>
#include <chrono>
using namespace std;
//==========================================
typedef long long ll;
ll ex_gcd(ll a,ll b,ll& x,ll& y)
{
    if(!b) { x=1, y=0; return a; }
    auto d = ex_gcd(b,a%b,y,x);
    y -= (a/b)*x;
    return d;
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
    ll a,b,x,y;
    cin>>a>>b;
    ex_gcd(a,b,x,y);
    cout<<(x+b)%b<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
