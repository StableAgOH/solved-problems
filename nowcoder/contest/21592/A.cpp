#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 505;
const int mod = 998244353;
int a[maxn][maxn];
int dp[2][maxn][maxn<<1];
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
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    if(max(p,q)>n+m-1) cout<<0<<endl;
    else
    {
        dp[0][1][0] = 1;
        for(int i=1;i<=n;i++)
        {
            int t = i%2;
            for(int j=1;j<=m;j++)
            {
                for(int k=a[i][j]==0;k<n+m;k++)
                {
                    int pre = a[i][j]?k:k-1;
                    dp[t][j][k] = (dp[t^1][j][pre]+dp[t][j-1][pre])%mod;
                }
                for(int k=0;k<n+m;k++) dp[t^1][j][k] = 0;
            }
        }
        int sum = 0;
        for(int i=p;i<=n+m-1-q;i++) sum = (sum+dp[n%2][m][i])%mod;
        cout<<sum<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
