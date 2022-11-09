#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
using namespace std;
const int maxn = 2e6;
typedef long long ll;
ll pre[maxn];
int main()
{
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ll x,n;
    cin>>x>>n;
    ll y = x;
    ll q = 1;
    while(y)
    {
        y /= 2;
        q *= 2;
    }
    auto f = [&](ll p) { return gcd((p*x)^x,x)==1; };
    for(int i=1;i<=q;i++) pre[i] = pre[i-1]+f(i);
    for(int i=0;i<n;i++)
    {
        ll l,r;
        cin>>l>>r;
        if((x&1)==0) cout<<0<<'\n';
        else
        {
            l--;
            ll s = pre[q]*((r/q)-(l/q));
            r %= q;
            l %= q;
            cout<<s+pre[r]-pre[l]<<'\n';
        }
    }
    return 0;
}
