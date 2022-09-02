#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double a,c;
    int b;
    cin>>a>>b>>c;
    if(b) a *= 1.26;
    else a *= 2.455;
    cout<<fixed<<setprecision(2)<<a<<' '<<(a>c?"T_T":"^_^")<<endl;
    return 0;
}
