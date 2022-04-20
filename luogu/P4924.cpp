#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 505;
int a[maxn][maxn], b[maxn][maxn];
void lrotate(int x1,int y1,int x2,int y2)
{
    memcpy(b, a, sizeof(a));
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            b[x2-(j-y1)][y1+(i-x1)] = a[i][j];
    memcpy(a, b, sizeof(b));
}
void rrotate(int x1,int y1,int x2,int y2)
{
    memcpy(b, a, sizeof(a));
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            b[x1+(j-y1)][y2-(i-x1)] = a[i][j];
    memcpy(a, b, sizeof(b));
}
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j] = (i-1)*n+j;
    while(m--)
    {
        int x,y,r,opt;
        cin>>x>>y>>r>>opt;
        if(opt) lrotate(x-r,y-r,x+r,y+r);
        else rrotate(x-r,y-r,x+r,y+r);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
