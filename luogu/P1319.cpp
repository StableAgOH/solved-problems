#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 205;
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
    int stop = n*n;
    int curx = 1;
    int cury = 1;
    bool isone = true;
    while(true)
    {
        isone = !isone;
        int tmp; 
        cin>>tmp;
        stop -= tmp;
        for(int i=1;i<=tmp;i++)
        {
            if(isone)
            {
                a[curx][cury] = 1;
                curx++;
            }
            else curx++;
            if(curx>n)
            {
                curx = 1;
                cury++;
            }
        }
        if(!stop) break;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[j][i];
        cout<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
