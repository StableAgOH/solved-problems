#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e5+5;
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
    int k,n;
    cin>>k>>n;
    for(int i=0;i<n;i++)
    {
        k += min(5,k/10);
        k += 5;
    }
    cout<<k<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
