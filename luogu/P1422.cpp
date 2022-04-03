#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <iomanip>
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
    double ele, money;
    cin>>ele;
    if(ele>150)
    {
        if (ele>=401) money=(ele-400)*0.5663+250*0.4663+150*0.4463;
        else money=(ele-150)*0.4663+150*0.4463;
    }
    else money=ele*0.4463;
    cout<<fixed<<setprecision(1)<<money<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
