#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
#include <vector>
#include <iomanip>
typedef long double ld;
const ld eps = 1e-8;
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
        int n;
        cin>>n;
        vector<ld> v(n), t(n);
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n;i++) cin>>t[i];
        auto f = [&](const ld m) {
            ld mx = -1;
            for(int i=0;i<n;i++) mx = max(mx, t[i]+abs(v[i]-m));
            return mx;
        };
        ld l=0, r=1e8;
        while(r-l>eps)
        {
            ld m = (l+r)/2;
            ld fm = f(m);
            if(f(m+eps)<fm) l = m;
            else r = m;
        }
        cout<<fixed<<setprecision(6)<<l<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
