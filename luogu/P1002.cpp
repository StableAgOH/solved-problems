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
const int maxn = 25;
long long dp[maxn][maxn];
bool mp[maxn][maxn];
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
    int x,y,n,m;
    cin>>x>>y>>n>>m;
    x+=2, y+=2, n+=2, m+=2;
    mp[n][m]=true;
    mp[n-2][m-1]=mp[n-2][m+1]=true;
    mp[n-1][m-2]=mp[n-1][m+2]=true;
    mp[n+1][m-2]=mp[n+1][m+2]=true;
    mp[n+2][m-1]=mp[n+2][m+1]=true;
    dp[2][2]=1;
    for(int i=2;i<=x;i++)
    {
        for(int j=2;j<=y;j++)
        {
            if(i==2&&j==2) continue;
            if(mp[i][j]) continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[x][y]<<endl;
    //======================================
    exit();
}