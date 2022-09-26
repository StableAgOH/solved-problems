#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(a[1]<a[n]) reverse(a+1, a+1+n);
    int cnt = 1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1]) cnt++;
        else break;
    }
    if(cnt&1) cout<<"Alice"<<'\n';
    else
    {
        cnt = 1;
        for(int i=n-1;i>=1;i--)
        {
            if(a[i]>a[i+1]) cnt++;
            else break;
        }
        if(cnt&1) cout<<"Alice"<<'\n';
        else cout<<"Bob"<<'\n';
    }
    return 0;
}
