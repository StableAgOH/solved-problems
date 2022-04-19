#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <iomanip>
const int maxn = 50;
typedef long long ll;
ll fib[maxn];
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
    fib[1] = fib[2] = 1;
    for(int i=3;i<=n;i++) fib[i] = fib[i-1]+fib[i-2];
    cout<<fixed<<setprecision(2)<<double(fib[n])<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
