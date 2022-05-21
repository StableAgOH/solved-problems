#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
#include <vector>
#include <cstring>
const int maxn = 105;
typedef pair<int,int> pii;
vector<pii> v;
int dp[maxn][maxn];
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
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.emplace_back(a,b);
    }
    sort(v.begin(),v.end());
    // dp[i][j] i 本书中留 j 本的结果
    // dp[?][1] = 0 other = INF
    // dp[i][j] = min(dp[i][j], dp[?][j-1]+|b[i]-b[?]|) j-1 <= ? <i
    // res = min(dp[i][n-k]) n-k <= i <= n
    memset(dp, 0x3f, sizeof(dp));
    for(int i=1;i<=n;i++) dp[i][1] = 0;
    for(int i=2;i<=n;i++)
        for(int j=2;j<=min(n-k,i);j++)
            for(int k=j-1;k<i;k++)
                dp[i][j] = min(dp[i][j], dp[k][j-1]+abs(v[i-1].second-v[k-1].second));
    int res = 0x3f3f3f3f;
    for(int i=n-k;i<=n;i++) res = min(res, dp[i][n-k]);
    cout<<res<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
