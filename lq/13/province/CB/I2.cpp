#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 105;
const int mod = 1e9+7;
typedef long long ll;
ll dp[maxn][maxn][maxn];
int n,m;
ll dfs(int i,int j,int k)
{
    if(!i&&!j&&k==2) return 1;
    if(~dp[i][j][k]) return dp[i][j][k];
    ll ret = 0;
    if(j&&k<=m-j) ret += dfs(i,j-1,k+1);
    if(i&&!(k&1)) ret += dfs(i-1,j,k/2);
    return dp[i][j][k] = ret%mod;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    cout<<dfs(n,m-1,1)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
