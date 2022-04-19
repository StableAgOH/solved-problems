#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
#include <vector>
#include <iterator>
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
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), inserter(v,v.begin()));
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int i) { cout<<i<<' '; });
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
