#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 25;
int a[maxn][maxn];
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
    int n;
    cin>>n;
    a[1][1] = a[2][1] = a[2][2] = 1;
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            a[i][j] = a[i-1][j-1]+a[i-1][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!a[i][j]) break;
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
