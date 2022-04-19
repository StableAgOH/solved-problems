#include <iostream>
#include <chrono>
using namespace std;
//==========================================
int a[40][40];
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
    n = (n+1)/2;
    int x = n - 1;
    int y = 0;
    n = 2*n-1;
    int nx, ny;
    for(int i=1;i<=n*n;i++)
    {
        a[y][x] = i;
        ny = (y-1+n)%n;
        nx = (x+1)%n;
        if((y==0&&x==n-1)||a[ny][nx]!=0) y++;
        else
        {
            y = ny;
            x = nx;
        }
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
            cout<<a[j][i]<<' ';
        cout<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
