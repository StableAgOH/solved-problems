#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1850;
int yh[maxn][maxn];
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
    if(n==1) cout<<1<<endl;
    else
    {
        yh[1][0] = yh[1][1] = 1;
        for(int i=2;i<=1825;i++)
        {
            yh[i][0] = 1;
            for(int j=1;j<=i;j++)
            {
                yh[i][j] = yh[i-1][j-1]+yh[i-1][j];
                if(yh[i][j]==n)
                {
                    cout<<i*(i+1)/2+j+1<<endl;
                    goto end;
                }
            }
        }
        int x=6;
        for(int i=4;x<=1e9;x+=i++)
        {
            if(x==n)
            {
                cout<<(long long)i*(i+1)/2+3<<endl;
                goto end;
            }
        }
        cout<<(long long)n*(n+1)/2+2<<endl;
    }
end:
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
