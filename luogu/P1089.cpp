#include <iostream>
#include <ctime>
using namespace std;
//==========================================
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
    int money = 0;
    int ck = 0;
    for(int i=1;i<=12;i++)
    {
        int ys;
        cin>>ys;
        money += 300;
        if(money<ys)
        {
            cout<<'-'<<i;
            goto end;
        }
        else
        {
            int data = money-ys;
            ck += data/100*100;
            money -= ys+data/100*100;
        }
    }
    cout<<int(ck*1.2+money)<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
