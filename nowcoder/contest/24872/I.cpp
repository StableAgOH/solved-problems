#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 105;
typedef long long ll;
ll v[maxn], w[maxn];
ll dp[maxn][maxn][2700];
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
    memset(dp, 0xcf, sizeof(dp));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int j=0;j<=m;j++) dp[0][j][1350] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=50;k<=2650;k++)
            {
                dp[i][j][k] = dp[i-1][j][k];
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-w[i]]+v[i]);
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k+w[i]]+v[i]);
                if(j)
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-2*w[i]]+v[i]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k+2*w[i]]+v[i]);
                }
            }
        }
    }
    ll ans = 0xcfcfcfcfcfcfcfcf;
    for(int j=0;j<=m;j++) ans = max(ans, dp[n][j][1350]);
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
