#include <iostream>
#include <chrono>
using namespace std;
//==========================================
int a[] = {29,31,28,31,30,31,30,31,31,30,31,30,31};
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
    int y,m;
    cin>>y>>m;
    if(m!=2) cout<<a[m]<<endl;
    else if(y%4==0&&y%100||y%400==0) cout<<a[0]<<endl;
    else cout<<a[2]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
