#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 105;
bool a[maxn][maxn];
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
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x+1][y-1] = a[x+1][y+3] = a[x-1][y+1] = a[x+3][y+1] = true;
        for(int j=x;j<=x+2;j++)
            for(int k=y;k<=y+2;k++)
                a[j][k] = true;
    }
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        for(int j=x-1;j<=x+3;j++)
            for(int k=y-1;k<=y+3;k++)
                a[j][k] = true;
    }
    int ans = 0;
    for(int i=2;i<=n+1;i++)
        for(int j=2;j<=n+1;j++)
            if(!a[i][j]) ans++;
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
