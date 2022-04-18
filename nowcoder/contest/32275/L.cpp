#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e7+5;
const int mod = 1e9+7;
typedef long long ll;
int f[maxn];
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int l;
        cin>>l;
        f[i] = l==i?i:1;
    }
    ll ans = 0;
    while(m--)
    {
        int x;
        cin>>x;
        ans = ans+f[x];
        if(ans>=mod) ans -= mod;
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
