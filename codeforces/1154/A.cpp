#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
#include <algorithm>
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int x[4];
    for(int i=0;i<4;i++) cin>>x[i];
    sort(begin(x), end(x));
    cout<<x[3]-x[0]<<' '<<x[3]-x[1]<<' '<<x[3]-x[2]<<endl;
    //======================================
    exit();
}