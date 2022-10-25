#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll square(ll x) { return x*x; }
int main()
{
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        if(abs(x-y)%3==0||abs(x-z)%3==0||abs(y-z)%3==0) cout<<square(x+y+z)<<'\n';
        else cout<<1+square(x+y+z-1)<<'\n';
    }
    return 0;
}
