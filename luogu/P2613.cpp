#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
typedef long long ll;
const int mod = 19260817;
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
void exgcd(ll a,ll b,ll& x,ll& y)
{
    if(!b) return x=1, y=0, void();
    exgcd(b, a%b, y, x);
    y -= a/b*x;
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
    string s1, s2;
    cin>>s1>>s2;
    ll a=0, b=0;
    for(auto c : s1)
    {
        a*=10;
        a+=c-'0';
        a%=mod;
    }
    for(auto c : s2)
    {
        b*=10;
        b+=c-'0';
        b%=mod;
    }
    // ll x,y;
    // exgcd(b,mod,x,y);
    // x=(x+mod)%mod;
    // cout<<a*x%mod<<endl;
    cout<<a*qpow(b, mod-2, mod)%mod<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
