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
#include <string>
const int maxn = 105;
int grid[maxn][maxn];
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
            if(s[j-1]=='*')
                grid[i][j]=9;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(grid[i][j]!=9)
            {
                for(int k=j-1;k<=j+1;k++)
                    if(grid[i-1][k]==9)
                        grid[i][j]++;
                for(int k=j-1;k<=j+1;k++)
                    if(grid[i+1][k]==9)
                        grid[i][j]++;
                if(grid[i][j-1]==9) grid[i][j]++;
                if(grid[i][j+1]==9) grid[i][j]++;
                cout<<grid[i][j];
            }
            else cout<<'*';
        }
        cout<<endl;
    }
    //======================================
    exit();
}