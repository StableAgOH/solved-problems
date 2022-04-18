#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 505;
typedef long long ll;
int dis[maxn][maxn];
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
    memset(dis, 0x3f, sizeof(dis));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) dis[i][i] = 0;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v] = dis[v][u] = min(w, dis[u][v]);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    int k;
    cin>>k;
    int last = 1;
    ll ans = 0;
    for(int i=0;i<k;i++)
    {
        int v;
        cin>>v;
        if(dis[last][v]==0x3f3f3f3f)
        {
            ans = -1;
            break;
        }
        ans += dis[last][v];
        last = v;
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
