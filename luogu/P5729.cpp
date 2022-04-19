#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 25;
int a[maxn][maxn][maxn];
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
    int w,x,h,q;
    cin>>w>>x>>h>>q;
    while(q--)
    {
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
                for(int k=z1;k<=z2;k++)
                    a[i][j][k] = 1;
    }
    int ans = 0;
    for(int i=1;i<=w;i++)
        for(int j=1;j<=x;j++)
            for(int k=1;k<=h;k++)
                if(!a[i][j][k]) ans++;
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
