#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
#include <iomanip>
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
        long double r;
        cin>>r;
        long double x,y,d;
        cin>>x>>y>>d;
        long double d1 = sqrt(x*x+y*y);
        long double d2 = d-d1;
        long double d3 = d1+d;
        long double ans = (asin(d3/r)+asin(d2/r))*r;
        cout<<fixed<<setprecision(12)<<ans<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
