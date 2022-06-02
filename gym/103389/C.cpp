#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 40;
int c[maxn], w[maxn];
int G[maxn][maxn];
int cnt[maxn];
int p[maxn];
int dp[maxn][1<<20];
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        cnt[c[i]]++;
    }
    int _ = 0;
    for(int i=1;i<=n;i++) if(cnt[i]>1) p[i] = _++;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u][v] = 1;
    }
    G[0][1] = 1;
    for(int f=0;f<n;f++)
    {
        for(int u=1;u<=n;u++)
        {
            if(!G[f][u]) continue;
            for(int s=0;s<(1<<_);s++)
            {
                int t = 1<<p[c[u]];
                int res = dp[f][s];
                if(cnt[c[u]]==1) res += w[c[u]];
                else if(s&t) res = max(res,dp[f][s-t]+w[c[u]]);
                dp[u][s] = max(dp[u][s], res);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int ans = 0;
        for(int s=0;s<(1<<_);s++)
            ans = max(ans, dp[i][s]);
        cout<<ans<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
