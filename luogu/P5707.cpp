#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
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
    int s,v;
    cin>>s>>v;
    int min = ceil(double(s)/v)+10;
    min = 8*60-min;
    if(min<0) min += 24*60;
    int a = min/60;
    int b = min%60;
    cout<<(a/10==0?"0":"")<<a<<':'<<(b/10==0?"0":"")<<b<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
