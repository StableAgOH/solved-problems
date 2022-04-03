#include <iostream>
#include <ctime>
using namespace std;
//==========================================
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
    istream_iterator<int> isit(cin);
    cout<<*isit++*0.2+*isit++*0.3+*isit++*0.5<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
