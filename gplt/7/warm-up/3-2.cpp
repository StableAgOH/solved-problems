#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1005;
const int maxw = 365*24*60+5;
int v[maxn], w[maxn];
int dp[maxw];
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
    int n,W;
    cin>>n>>W;
    int sum = 0;
    for(int i=1;i<=n;i++) cin>>w[i], sum += w[i];
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        sum -= w[i];
        for(int j=W;j>=max(W-sum,w[i]);j--)
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    }
    cout<<dp[W]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
