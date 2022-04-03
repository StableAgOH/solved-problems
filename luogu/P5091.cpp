#include <iostream>
#include <ctime>
using namespace std;
//==========================================
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
    int a,m;
    string b;
    cin>>a>>m>>b;
    int tmp = 0;
    int phim = phi(m);
    bool flag = false;
    for(auto c : b)
    {
        tmp = tmp*10+c-'0';
        if(tmp>=phim)
        {
            flag = true;
            tmp %= phim;
        } 
    }
    if(flag) tmp += phim;
    cout<<qpow(a, tmp, m)<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
