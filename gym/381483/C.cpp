#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
const int mod = 1e9+7;
const int inv2 = 500000004;
const int inv6 = 166666668;
typedef long long ll;
int C3(int n) { return ll(n)*(n-1)%mod*(n-2)%mod*inv6%mod; }
int f(int n)
{
    ll s = 0;
    ll t = 1;
    ll i = 1;
    for(;i<=n;i+=(t<<=1)) s = (s+t*(t-1))%mod;
    i -= t;
    if(i!=n) s = (s+(n-i-1)*(n-i))%mod;
    return s*inv2%mod;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<(C3(n)-f(n)+mod)%mod<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
