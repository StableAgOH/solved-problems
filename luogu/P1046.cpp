#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
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
    vector<int> v;
    copy_n(istream_iterator<int>(cin), 10, inserter(v, v.begin()));
    cout<<count_if(v.begin(), v.end(), [](int x) { return x-30<=*istream_iterator<int>(cin); })<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
