#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 55;
int a[maxn];
int n;
bool check(int m)
{
    int l=0, r=1e9;
    for(int i=1;i<=n;i++)
    {
        l=max(l+1,a[i]-m);
        r=a[i]+m;
        if(l>r) return false;
    }
    return true;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=0, r=1e9;
    while(l<r)
    {
        int m = (l+r)>>1;
        if(check(m)) r=m;
        else l=m+1;
    }
    cout<<l<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
