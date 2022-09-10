#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <tuple>
#include <vector>
#include <numeric>
#include <functional>
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tp3;
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
    int n,m,q;
    cin>>n>>m>>q;
    vector<ll> val(2*n);
    val[0] = inf;
    for(int i=1;i<=n;i++) cin>>val[i];
    vector<tp3> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.emplace_back(w,u,v);
    }
    int rt = 1;
    vector<int> G[2*n];
    vector<int> fa(2*n);
    iota(fa.begin(), fa.end(), 0);
    function<int(int)> find = [&](int x) { return x==fa[x]?x:fa[x]=find(fa[x]); };
    sort(edges.begin(), edges.end());
    int cnt = 0;
    for(auto&& [w,u,v] : edges)
    {
        int fu=find(u), fv=find(v);
        if(fu==fv) continue;
        cnt++;
        int x = n+cnt;
        val[x] = w;
        G[x].push_back(fu);
        G[x].push_back(fv);
        fa[fu] = fa[fv] = x;
        if(cnt==n-1)
        {
            rt = x;
            break;
        }
    }
    vector<ll> sum(2*n);
    array<vector<int>, 20> acs;
    for(auto&& v : acs) v.resize(2*n);
    function<void(int,int)> dfs = [&](int u,int f) {
        acs[0][u] = f;
        for(int i=1;i<20;i++) acs[i][u] = acs[i-1][acs[i-1][u]];
        if(u<=n) sum[u] = val[u];
        for(auto v : G[u])
        {
            dfs(v,u);
            sum[u] += sum[v];
        }
    };
    dfs(rt, 0);
    while(q--)
    {
        int u,k;
        cin>>u>>k;
        while(true)
        {
            int v = u;
            ll s = sum[u];
            for(int i=19;i>=0;i--) if(s+k>=val[acs[i][v]]) v = acs[i][v];
            if(v==u) break;
            u = v;
        }
        cout<<sum[u]+k<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
