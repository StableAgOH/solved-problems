#include <iostream>
using namespace std;
const int maxn = 105;
int a[maxn][maxn];
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n,k,x;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    int cnt = 0;
    for(int i=2;i<=n;i+=2)
    {
        cnt++;
        if(cnt==k+1) cnt = 1;
        for(int j=n;j>=cnt+1;j--)
            a[j][i] = a[j-cnt][i];
        for(int j=1;j<=cnt;j++)
            a[j][i] = x;
    }
    for(int i=1;i<=n;i++)
    {
        int sum = 0;
        for(int j=1;j<=n;j++)
            sum += a[i][j];
        cout<<sum;
        if(i!=n) cout<<' ';
    }
    return 0;
}
