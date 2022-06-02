#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
const int maxn = 305;
typedef long long ll;
typedef tuple<ll,int,int> tp3;
ll dis[maxn][maxn];
bool s[maxn];
vector<tp3> edges;
int fa[maxn];
int find(int x) { return x==fa[x]?x:fa[x]=find(fa[x]); }
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
    memset(dis, 0x3f, sizeof(dis));
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    for(int i=1;i<=n;i++) dis[i][i] = 0;
    iota(fa+1, fa+1+n, 1);
    int cnt = n;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v] = dis[v][u] = w;
        int fu=find(u), fv=find(v);
        if(fu==fv) continue;
        fa[fu] = fv;
        cnt--;
    }
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        s[x] = true;
    }
    if(cnt!=1||t==0) cout<<-1<<endl;
    else
    {
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
        for(int u=1;u<=n;u++)
            for(int v=1;v<=n;v++)
                if(s[u]&&s[v]) edges.emplace_back(dis[u][v],u,v);
        sort(edges.begin(), edges.end());
        iota(fa+1, fa+1+n, 1);
        cnt = n;
        ll mx = -1;
        for(auto [w,u,v] : edges)
        {
            int fu=find(u), fv=find(v);
            if(fu==fv) continue;
            fa[fu] = fv;
            cnt--;
            mx = max(mx, w);
        }
        for(int u=1;u<=n;u++)
        {
            if(s[u]) continue;
            ll t = 0x3f3f3f3f3f3f3f3f;
            for(int v=1;v<=n;v++)
                if(s[v]) t = min(t, dis[u][v]<<1);
            mx = max(mx, t);
        }
        cout<<ll(ceil(double(mx)/t))<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
