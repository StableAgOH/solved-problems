#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n;
    cin>>n;
    long double ans = 1.0/n;
    cout<<fixed<<setprecision(15)<<ans<<endl;
    return 0;
}