#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <tuple>
#include <vector>
#include <random>
#include <cstring>
const int maxn = 25;
const int maxm = 405;
const int mod = 998244353;
typedef long long ll;
typedef tuple<int,int,int> tp3;
vector<tp3> cps[maxn];
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
int n;
int dp[maxn][maxm][maxm];
int calc(int x,int y,int z)
{
    int cnt = 0;
    for(int i=1;i<=n;i++)
        if(dp[i][x][y]<=z) cnt++;
    return cnt;
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
    memset(dp, 0x3f, sizeof(dp));
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            cps[i].emplace_back(a,b,c);
            dp[i][a][b] = min(dp[i][a][b], c);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=400;j++)
        {
            for(int k=1;k<=400;k++)
            {
                dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k]);
                dp[i][j][k] = min(dp[i][j][k], dp[i][j][k-1]);
            }
        }
    }
    ll seed;
    cin>>seed;
    mt19937 rng(seed);
    uniform_int_distribution<> u(1,400);
    ll inv = qpow(seed, mod-2, mod);
    ll psd = qpow(seed, q, mod);
    ll ans = 0;
    int lastans = 0;
    for (int i=1;i<=q;i++)
    {
        int IQ = (u(rng)^lastans)%400+1;
        int EQ = (u(rng)^lastans)%400+1;
        int AQ = (u(rng)^lastans)%400+1;
        lastans = calc(IQ,EQ,AQ);
        psd = psd*inv%mod;
        ans = (ans+lastans*psd%mod)%mod;
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
