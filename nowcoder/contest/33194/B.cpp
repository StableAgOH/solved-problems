#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 8005;
const int mod = 998244353;
typedef long long ll;
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
ll a[maxn], inv[maxn];
ll dp[maxn][maxn];
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    inv[1] = 1;
    for(int i=2;i<=n;i++) inv[i] = (ll)(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<n;i++) cin>>a[i];
    dp[1][0] = 1;
    dp[2][1] = (dp[2][1]+dp[1][0]*inv[a[1]]%mod)%mod;
    dp[1+a[1]+1][1] = (dp[1+a[1]+1][1]-dp[1][0]*inv[a[1]]%mod+mod)%mod;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
            auto p = dp[i][j]*inv[a[i]]%mod;
            dp[i+1][j+1] = (dp[i+1][j+1]+p)%mod;
            dp[i+a[i]+1][j+1] = (dp[i+a[i]+1][j+1]-p+mod)%mod;
        }
        for(int j=i;j<=n;j++) dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
    }
    ll ans = 0;
    for(int i=1;i<n;i++) ans = (ans+dp[n][i]*dp[n][i]%mod)%mod;
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
