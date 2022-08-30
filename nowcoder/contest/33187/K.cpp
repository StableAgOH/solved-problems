#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 205;
const int mod = 1e9+7;
typedef long long ll;
char s[maxn];
ll dp[maxn][maxn][maxn>>1];
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
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        int n,m;
        cin>>n>>m;
        cin.get();
        for(int i=1;i<=n;i++) s[i] = cin.get();
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j][0] = dp[i-1][s[j]==')'?j-1:j][1];
                for(int k=1;k*2<=m;k++)
                    dp[i][j][k] = (dp[i-1][s[j]=='('?j-1:j][k-1]+dp[i-1][s[j]==')'?j-1:j][k+1])%mod;
            }
        }
        cout<<dp[m][n][0]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
