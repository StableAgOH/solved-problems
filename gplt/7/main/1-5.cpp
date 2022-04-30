#include <iostream>
using namespace std;
int a[10];
bool b[10][10];
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    for(int i=1;i<=6;i++)
    {
        cin>>a[i];
        b[i][a[i]] = true;
    }
    int k;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=6;j++)
        {
            for(int p=6;p>=1;p--)
            {
                if(!b[j][p])
                {
                    b[j][p] = true;
                    if(i==k)
                    {
                        cout<<p;
                        if(j!=6) cout<<' ';
                    }
                    break;
                }
            }
        }
    }
    return 0;
}