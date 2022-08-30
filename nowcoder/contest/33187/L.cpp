#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxm = 2e3+5;
int dp[2][maxm];
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
    dp[0][1] = 1;
    int ans = 1e9;
    for(int i=1;i<=n;i++)
    {
        int k = i&1;
        memcpy(dp[k], dp[k^1], sizeof(dp[k]));
        dp[k][1] = i+1;
        int l;
        cin>>l;
        for(int j=0;j<l;j++)
        {
            int u,v;
            cin>>u>>v;
            dp[k][v] = max(dp[k][v], dp[k^1][u]);
        }
        if(dp[k][m]) ans = min(ans, i-dp[k][m]+1);
    }
    cout<<(ans==1e9?-1:ans)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
