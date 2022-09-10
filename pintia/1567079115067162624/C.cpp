#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
const int mod = 1e9+7;
typedef long long ll;
ll fac[maxn];
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    fac[0] = 1;
    for(int i=1;i<=100000;i++) fac[i] = fac[i-1]*i%mod;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.length();
        int x = count(s.begin(), s.end(), '1');
        if(!x) cout<<fac[n-1]*n%mod<<'\n';
        else cout<<fac[n-1]*(2*n-x)%mod*qpow(2,x-1,mod)%mod<<'\n';
    }
    return 0;
}
