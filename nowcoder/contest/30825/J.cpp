#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
typedef long long ll;
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
int phi(int n)
{
    int res = n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res = res/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) res = res/n*(n-1);
    return res;
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
    int t;
    cin>>t;
    while(t--)
    {
        int a,p;
        string k;
        cin>>a>>k>>p;
        int phip = phi(p);
        ll b = 0;
        for(auto c : k)
        {
            b = b*10+c-'0';
            b%=phip;
        }
        cout<<qpow(a,b,p)<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
