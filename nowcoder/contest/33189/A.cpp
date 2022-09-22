#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
#include <iomanip>
const int maxn = 1e5+5;
typedef long double ld;
struct S { ld w,p; } a[maxn];
ld dp[maxn][25];
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
    for(int i=1;i<=n;i++) cin>>a[i].w;
    for(int i=1;i<=n;i++)
    {
        int q;
        cin>>q;
        a[i].p = q/1e4;
    }
    sort(a+1, a+1+n, [](S& x,S& y){ return (x.p-1)/x.w<(y.p-1)/y.w; });
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]*a[i].p+a[i].w);
    cout<<fixed<<setprecision(10)<<dp[n][m]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
