#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
#include <iomanip>
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    double a,b,c;
    cin>>a>>b>>c;
    double p = 0.5*(a+b+c);
    cout<<fixed<<setprecision(1)<<sqrt(p*(p-a)*(p-b)*(p-c))<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
