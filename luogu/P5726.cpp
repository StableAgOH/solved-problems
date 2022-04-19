#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <iomanip>
vector<int> v;
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
    copy_n(istream_iterator<int>(cin), n, inserter(v,v.begin()));
    sort(v.begin(), v.end());
    cout<<fixed<<setprecision(2)<<accumulate(v.begin()+1, v.end()-1, 0.0)/(v.size()-2)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
