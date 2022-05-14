#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
const int mod = 998244353;
const int inv6 = 166374059;
typedef long long ll;
inline ll ps(ll n)
{
    return n*(n+1)%mod*(2*n+1)%mod*inv6%mod;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll sum = 0;
        for(ll l=1,r;l<=n;l=r+1)
        {
            r = n/(n/l);
            ll t = (ps(r)-ps(l-1))%mod;
            if(t<0) t += mod;
            sum = (sum+t*(n/l)%mod)%mod;
        }
        ll t = ps(n);
        sum = (sum+t)%mod;
        for(ll i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                sum -= i*i%mod;
                if(sum<0) sum += mod;
                if(i*i==n) break;
                sum -= ((n/i)*(n/i))%mod;
                if(sum<0) sum += mod;
            }
        }
        cout<<sum<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
