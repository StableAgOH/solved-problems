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
    double x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    double d1 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double d2 = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    double d3 = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    cout<<fixed<<setprecision(2)<<d1+d2+d3<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
