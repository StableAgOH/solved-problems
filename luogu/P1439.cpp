#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <algorithm>
const int maxn = 1e5+5;
int mp[maxn], a[maxn], d[maxn], len;
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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]=mp[x];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]>d[len]) d[++len]=a[i];
        else *upper_bound(d+1, d+1+len, a[i]) = a[i];
    }
    cout<<len<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
