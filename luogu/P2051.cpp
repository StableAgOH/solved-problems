#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 105;
const int mod = 9999973;
typedef long long ll;
ll dp[maxn][maxn][maxn];
ll C2(ll n) { return n*(n-1)/2; }
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
    int n,m;
    cin>>n>>m;
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=m-j;k++)
            {
                dp[i][j][k] = dp[i-1][j][k];    // 0
                if(j) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j-1][k]*(m-j-k+1))%mod;  // 1->0
                if(k) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j+1][k-1]*(j+1))%mod;  // 1->1
                if(j>1) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j-2][k]*C2(m-j-k+2))%mod;  // 2->00
                if(k) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j][k-1]*(m-j-k+1)*j)%mod; // 2->01
                if(k>1) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j+2][k-2]*C2(j+2))%mod;  // 2->11
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<=m;i++)
        for(int j=0;j<=m;j++)
            ans = (ans+dp[n][i][j])%mod;
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}