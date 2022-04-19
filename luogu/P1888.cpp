#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
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
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a, a+3);
    cout<<a[0]/__gcd(a[0],a[2])<<'/'<<a[2]/__gcd(a[0],a[2])<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
