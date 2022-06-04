#include <iostream>
#include <ctime>
using namespace std;
//==========================================
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    long long n;
    cin>>n;
    n++;
    if(n==1) cout<<0<<endl;
    else if(n%2) cout<<n<<endl;
    else cout<<n/2<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}