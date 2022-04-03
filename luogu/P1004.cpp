#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <algorithm>
const int maxn = 11;
int a[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
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
    int n;
    cin>>n;
    while(true)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(!x) break;
        a[x][y]=z;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                for(int l=1;l<=n;l++)
                {
                    dp[i][j][k][l] = max({dp[i-1][j][k-1][l], dp[i-1][j][k][l-1], dp[i][j-1][k-1][l], dp[i][j-1][k][l-1]}) + a[i][j] + a[k][l];
                    if(i==k&&j==l) dp[i][j][k][l] -= a[i][j];
                }
            }
        }
    }
    cout<<dp[n][n][n][n]<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
