#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
const int maxn = 1e5+5;
const int mod = 998244353;
typedef long long ll;
vector<int> G[maxn];
int siz[maxn];
void dfs1(int u,int f)
{
    siz[u] = 1;
    for(auto v : G[u])
    {
        if(v==f) continue;
        dfs1(v,u);
        siz[u] += siz[v];
    }
}
ll ffac[maxn];
ll dp[maxn];
void dfs2(int u,int f)
{
    ll mul = 1;
    int cnt = 0;
    for(auto v : G[u])
    {
        if(v==f) continue;
        dfs2(v,u);
        mul = mul*dp[v]%mod;
        if(siz[v]&1) cnt++;
    }
    if(!cnt) dp[u] = mul;
    else if(cnt&1) dp[u] = ffac[cnt]*mul%mod;
    else dp[u] = ffac[cnt-1]*mul%mod;
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
    int n;
    cin>>n;
    ffac[0] = ffac[1] = 1;
    for(int i=2;i<=n;i++) ffac[i] = ffac[i-2]*i%mod;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    cout<<dp[1]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
