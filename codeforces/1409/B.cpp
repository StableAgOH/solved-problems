#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
const int maxn = 1e5+5;
typedef long long ll;
ll calc(ll a, ll b, ll x, ll y, ll n)
{
    if(a-x<=n)
    {
        n-=a-x;
        return x*(b-y<=n?y:b-n);
    }
    else return (a-n)*b;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        cout<<min(calc(a,b,x,y,n), calc(b,a,y,x,n))<<endl;
    }
    //======================================
    exit();
}