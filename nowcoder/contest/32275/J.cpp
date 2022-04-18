#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e6+5;
typedef long long ll;
const ll mod = 114514919810;
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
    a[1] = a[2] = 1;
    for(int i=3;i<=1e6;i++) a[i] = (a[i-1]+a[i-2]+1)%mod;
    for(int i=1;i<=1e6;i++) pre[i] = (pre[i-1]+a[i])%mod;
    int t;
    cin>>t;
    while(t--)
    {
        int p;
        cin>>p;
        cout<<pre[p]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
