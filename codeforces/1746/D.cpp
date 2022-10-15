#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <array>
#include <vector>
#include <numeric>
#include <functional>
#include <unordered_map>
typedef long long ll;
inline constexpr ll hs(ll x,ll y) { return x*(1e9+1)+y+1; }
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> G[n+1];
        for(int i=2;i<=n;i++)
        {
            int p;
            cin>>p;
            G[p].push_back(i);
        }
        vector<ll> s(n+1);
        for(int i=1;i<=n;i++) cin>>s[i];
        unordered_map<ll,ll> dp;
        function<void(int,ll)> dfs1 = [&](int u,ll x) {
            ll t = hs(u,x);
            ll r = hs(u,x+1);
            dp[t] = s[u]*x;
            dp[r] = s[u]*(x+1);
            if(G[u].empty()) return;
            int p = x/G[u].size();
            int q = x%G[u].size();
            vector<ll> vec;
            ll sum = 0;
            for(auto v : G[u])
            {
                dfs1(v,p);
                sum += dp[hs(v,p)];
                vec.push_back(dp[hs(v,p+1)]-dp[hs(v,p)]);
            }
            sort(vec.begin(), vec.end(), greater<>());
            ll pre = accumulate(vec.begin(), vec.begin()+q, 0LL);
            dp[t] += sum+pre;
            dp[r] += sum+pre+vec[q];
        };
        dfs1(1,k);
        cout<<dp[hs(1,k)]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
