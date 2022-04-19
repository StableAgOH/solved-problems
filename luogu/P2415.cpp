#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
typedef long long ll;
vector<ll> v;
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
    copy(istream_iterator<ll>(cin), istream_iterator<ll>(), inserter(v,v.begin()));
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    sum *= 1<<(v.size()-1);
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
