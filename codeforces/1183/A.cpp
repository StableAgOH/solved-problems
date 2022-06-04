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
const int maxn = 1e5+5;
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
    int n;
    cin>>n;
    int s1=0, x=n;
    while(x)
    {
        s1+=x%10;
        x/=10;
    }
    if(s1%4)
    {
        for(int i=n+1;;i++)
        {
            x=i;
            s1=0;
            while(x)
            {
                s1+=x%10;
                x/=10;
            }
            if(s1%4==0)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    else cout<<(n?n:4)<<endl;
    //======================================
    exit();
}