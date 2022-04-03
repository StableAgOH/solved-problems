#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <set>
#include <algorithm>
#include <iterator>
set<int> s;
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
    int n;
    cin>>n;
    copy_n(istream_iterator<int>(cin), n, inserter(s, s.begin()));
    cout<<s.size()<<endl;
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
