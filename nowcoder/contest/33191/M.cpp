#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
#include <functional>
const int maxn = 505;
char grid[maxn][maxn];
int dp[maxn][maxn];
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
        int n,m;
        cin>>n>>m;
        cin.get();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                grid[i][j] = cin.get();
            cin.get();
        }
        function<int(int,int,int)> dfs = [&](int x,int y,int c) {
            if(dp[x][y]) return dp[x][y];
            int ret = 0;
            if((x+y)&1)
            {
                ret = c;
                if(x+1<=n&&dfs(x+1,y,c)!=c) ret = -1;
                else if(y+1<=m&&dfs(x,y+1,c)!=c) ret = -1;
            }
            else
            {
                if((x+1<=n&&dfs(x+1,y,c)==c)||(y+1<=m&&dfs(x,y+1,c)==c)) ret = c;
                else ret = -1;
            }
            return dp[x][y] = ret;
        };
        auto solve = [&](int c) {
            memset(dp, 0, sizeof(dp));
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(grid[i][j]=='A') dp[i][j] = 1;
                    if(grid[i][j]=='B') dp[i][j] = 2;
                }
            }
            if(grid[n][m]=='.') dp[n][m] = 3;
            cout<<(dfs(1,1,c)==c?"yes":"no")<<' ';
        };
        solve(1);
        solve(3);
        solve(2);
        cout<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
