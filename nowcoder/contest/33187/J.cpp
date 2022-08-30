#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <numeric>
#include <iomanip>
#include <cmath>
typedef long long ll;
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
        ll n;
        cin>>n;
        long double sx=0, sx2=0, sy=0, sxy=0;
        vector<ll> v(n+1);
        for(ll i=1;i<=n;i++)
        {
            cin>>v[i];
            sx += i;
            sx2 += i*i;
            sy += v[i];
            sxy += i*v[i];
        }
        long double a = (n*sxy-sx*sy)/(n*sx2-sx*sx);
        long double b = (sy-a*sx)/n;
        long double q = 0;
        for(int i=1;i<=n;i++)
        {
            long double t = v[i]-(a*i+b);
            q += t*t;
        }
        cout<<fixed<<setprecision(15)<<q<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
