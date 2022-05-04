#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 255;
const int maxw = 1005;
const double eps = 1e-5;
int n,W;
int a[maxn], b[maxn];
double dp[maxw];
bool check(double m)
{
    fill(dp+1, dp+1+W, -1e9);
    for(int i=1;i<=n;i++)
    {
        for(int j=W;j>=0;j--)
        {
            int t = min(W, j+b[i]);
            dp[t] = max(dp[t], dp[j]+a[i]-m*b[i]);
        }
    }
    return dp[W]>0;
}
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
    cin>>n>>W;
    for(int i=1;i<=n;i++) cin>>b[i]>>a[i];
    double l=0, r=1e3;
    while(r-l>eps)
    {
        double mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout<<int(l*1000)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
