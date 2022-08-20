#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <cstring>
const int maxn = 5005;
const int mod = 998244353;
typedef long long ll;
ll dp[11][maxn];
ll C[maxn][maxn];
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
    int n;
    cin>>n;
    C[0][0] = C[1][0] = C[1][1] = 1;
    for(int i=2;i<=n;i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j=1;j<i;j++)
            C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
    }
    string s;
    cin>>s;
    dp[0][0] = 1;
    for(int i=1;i<=10;i++)
    {
        switch(s[i-1])
        {
        case 'x':
            memcpy(dp[i], dp[i-1], sizeof(ll)*(n+1));
            break;
        default:
            for(int j=s[i-1]=='o';j<=n;j++)
                for(int k=s[i-1]=='o';k<=j;k++)
                    dp[i][j] = (dp[i][j]+dp[i-1][j-k]*C[n-j+k][k])%mod;
        }
    }
    cout<<dp[10][n]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
