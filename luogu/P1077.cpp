#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 105;
const int mod = 1e6+7;
typedef long long ll;
int a[maxn];
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0][0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=min(j,a[i]);k++)
                dp[i][j] = (dp[i][j]+dp[i-1][j-k])%mod;
    cout<<dp[n][m]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
