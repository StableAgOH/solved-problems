#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
const int mod = 1e9+7;
typedef long long ll;
ll fac[maxn];
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    fac[1] = 1;
    for(int i=2;i<=1e5;i++)
        fac[i] = fac[i-1]*(2*i-1)%mod;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<fac[n]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
