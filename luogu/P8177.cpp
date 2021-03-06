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
    freopen("../in.in", "r", stdin);
    freopen("../out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        long long n,a,d;
        cin>>n>>a>>d;
        long long ans = 0;
        while(d%2==0)
        {
            d/=2;
            ans+=n-1;
            n+=n-1;
        }
        cout<<ans<<endl;
    }
    //======================================
    exit();
}