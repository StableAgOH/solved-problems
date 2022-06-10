#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
#include <cmath>
const int maxn = 1e5+5;
typedef int64_t ll;
int64_t ex_gcd(int64_t a, int64_t b, int64_t& x, int64_t& y)
{
    if(!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    auto d = ex_gcd(b, a % b, y, x);
    y -= (a / b) * x;
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
    ll a,b,c;
    cin>>a>>b>>c;
    ll g = __gcd(a,b);
    if(c%g==0)
    {
        ll x,y;
        ex_gcd(a,b,x,y);
        x = x*c/g;
        y = y*c/g;
        if(x<0)
        {
            ll t = ceil(-x/double(b));
            x += t*b;
            y -= a*t;
        }
        else if(y<0)
        {
            ll t = -ceil(-y/double(a));
            x += t*b;
            y -= a*t;
        }
        if(x<0||y<0) cout<<-1<<endl;
        else cout<<x<<' '<<y<<endl;
    }
    else cout<<-1<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
