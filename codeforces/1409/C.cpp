#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
#include <cmath>
#include <algorithm>
const int maxn = 55;
int a[maxn], cnt;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        cnt=0;
        int n,x,y;
        cin>>n>>x>>y;
        int sub = y-x;
        for(int i=1;i<=sub;i++)
        {
            if(sub%i==0)
            {
                if(sub/i>n-1) continue;
                if(y/i>=n)
                {
                    for(int j=y;n;j-=i,n--)
                        a[cnt++]=j;
                }
                else
                {
                    for(int j=y;j>0;j-=i,n--)
                        a[cnt++]=j;
                    for(int j=y+i;n;n--,j+=i)
                        a[cnt++]=j;
                }
                sort(a, a+cnt);
                for(int i=0;i<cnt;i++)
                    cout<<a[i]<<' ';
                cout<<endl;
                break;
            }
        }
    }
    //======================================
    exit();
}