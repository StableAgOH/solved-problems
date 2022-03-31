#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 205;
int a[maxn];
int dis[maxn][maxn];
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    memset(dis,0x3f,sizeof(dis));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) dis[i][i]=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=dis[v][u]=w;
    }
    int q;
    cin>>q;
    int k=0;
    while(q--)
    {
        int x,y,t;
        cin>>x>>y>>t;
        while(k<n&&a[k]<=t)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
            k++;
        }
        cout<<(a[x]>t||a[y]>t||dis[x][y]==0x3f3f3f3f?-1:dis[x][y])<<'\n';
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}