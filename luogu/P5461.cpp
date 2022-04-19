#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1050;
int a[maxn][maxn];
void full(int x,int y,int z)
{
    if(z==1) a[x][y]=1;
    else
    {
        int tmp = z>>1;
        full(x+tmp, y, tmp);
        full(x, y+tmp, tmp);
        full(x+tmp, y+tmp, tmp);
    }
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
    int n;
    cin>>n;
    full(1,1,(1<<n));
    for(int i=1;i<=(1<<n);i++)
    {
        for(int j=1;j<=(1<<n);j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
