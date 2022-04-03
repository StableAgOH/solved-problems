#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <numeric>
#include <iterator>
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
    cout<<accumulate(istream_iterator<int>(cin), istream_iterator<int>(), 0)<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
