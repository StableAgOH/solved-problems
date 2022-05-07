#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <iomanip>
const int maxn = 1e6+5;
const double eps = 1e-8;
const double ec = 0.57721566490153286060651209008240243104215933593992;
double psi[maxn];
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
    psi[1] = -ec;
    for(int i=2;i<=1e6;i++) psi[i] = 1.0/(i-1)+psi[i-1];
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<fixed<<setprecision(6)<<psi[n]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
