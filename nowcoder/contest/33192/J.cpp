#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int mod = 998244353;
typedef long long ll;
ll dp[66][66][4100];
ll C[66][66];
void add(ll& a,ll b)
{
    a += b;
    if(a>=mod) a -= mod;
}
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
    int n,k,t;
    cin>>n>>k>>t;
    const int p = 2*t+n+1;
    C[0][0] = 1;
    for(int i=1;i<=n+1;i++)
    {
        C[i][0] = 1;
        for(int j=1;j<=i;j++)
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
    }
    for(int i=0;i<=n;i++) dp[0][i][(i+1)*(i+1)] = C[n][i];
    for(int i=1;i<k;i++)
        for(int j=0;j<=n;j++)
            for(int l=0;l<=j;l++)
                for(int s=l*l;s<=p;s++)
                    if(dp[i-1][j-l][s-l*l])
                        add(dp[i][j][s], dp[i-1][j-l][s-l*l]*C[n-(j-l)][l]%mod);
    cout<<dp[k-1][n][p]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
