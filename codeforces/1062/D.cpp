#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e5+5;
typedef long long ll;
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    ll ans = 0;
    for(int i=-n;i<=-2;i++)
    {
        for(int j=-2;(i*j)<=n;j--)
            ans += -j;
        for(int j=2;-i*j<=n;j++)
            ans += j;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=-2;i*(-j)<=n;j--)
            ans += -j;
        for(int j=2;i*j<=n;j++)
            ans += j;
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}