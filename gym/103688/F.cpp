#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 10;
int dis[maxn][maxn];
inline void ae(int u,int v) { dis[u][v] = dis[v][u] = 1; }
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
    memset(dis, 0x3f, sizeof(dis));
    for(int i=1;i<=7;i++) dis[i][i] = 0;
    ae(1,2); ae(1,3); ae(2,4); ae(3,4); ae(4,5); ae(4,6); ae(5,7); ae(6,7);
    for(int i=1;i<=7;i++)
        for(int j=1;j<=7;j++)
            for(int k=1;k<=7;k++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j] = dis[i][k]+dis[k][j];
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<min(dis[a][c]+dis[b][d], dis[a][d]+dis[b][c])<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
