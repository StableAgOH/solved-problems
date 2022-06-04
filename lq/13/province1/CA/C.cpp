#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 2e5+5;
typedef long long ll;
ll a[maxn], pre[maxn];
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
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];
    }
    ll sum = 0;
    for(int i=1;i<=n;i++)
        sum += a[i] * (pre[n]-pre[i]);
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
