#include <iostream>
#include <ctime>
using namespace std;
//==========================================
typedef long long ll;
ll sigma(ll n)
{
    ll sum = 0;
    for(ll l=1,r;l<=n;l=r+1)
    {
        r = n/(n/l);
        sum += (r-l+1)*(n/l)*(l+r)/2;
    }
    return sum;
}
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
    int x,y;
    cin>>x>>y;
    cout<<sigma(y)-sigma(x-1)<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
