#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <iomanip>
#include <numeric>
const int maxn = 15;
typedef long double ld;
const ld eps = 1e-6;
int n;
ld a[maxn];
ld f(const ld x)
{
    ld p=1, sum=0;
    for(int i=n;i>=0;i--)
    {
        sum += a[i]*p;
        p *= x;
    }
    return sum;
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
    ld l,r;
    cin>>n>>l>>r;
    for(int i=0;i<=n;i++) cin>>a[i];
    while(r-l>eps)
    {
        ld m = midpoint(l,r);
        ld fm = f(m);
        if(f(m+eps)>fm) l = m;
        else r = m;
    }
    cout<<fixed<<setprecision(6)<<l<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
