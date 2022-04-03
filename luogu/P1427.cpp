#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <iterator>
#include <algorithm>
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
    vector<int> v((istream_iterator<int>(cin)), istream_iterator<int>());
    copy(v.rbegin()+1, v.rend(), ostream_iterator<int>(cout, " "));
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}