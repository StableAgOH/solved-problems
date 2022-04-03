#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
set<string> s;
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
    copy_n(istream_iterator<string>(cin), n, inserter(s, s.begin()));
    cout<<s.size()<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
