#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cmath>
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    double s, x;
    cin>>s>>x;
    int cnt=0;
    bool flag = false;
    for(double i=0;;i+=7*pow(0.98,cnt++))
    {
        if(i>s+x)
        {
            flag = false;
            cout<<'n'<<endl;
            break;
        }
        if(flag)
        {
            cout<<'y'<<endl;
            break;
        }
        if(i>=s-x) flag = true;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
