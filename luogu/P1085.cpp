#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e5+5;
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
    int mxh=0, mxd=0;
    for(int i=1;i<=7;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x+y>8&&x+y>mxh)
        {
            mxh = x+y;
            mxd = i;
        }
    }
    cout<<mxd<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
