#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int mod = 1e9+7;
const int inv6 = 166666668;
typedef long long ll;
ll C3(ll x) { return x*(x-1)%mod*(x-2)%mod*inv6%mod; }
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
    int _t;
    cin>>_t;
    while(_t--)
    {
        int n;
        cin>>n;
        ll c = C3(n);
        ll s = 0;
        ll t = 1;
        ll i = 1;
        for(;i<=n;i+=(t<<=1))
            s = (s+t*(t*2-2)/2)%mod;
        i -= t;
        if(i!=n) s = (s+((n-i-1)<<1)*(n-i)/2)%mod;
        cout<<(c-s/2+mod)%mod<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
