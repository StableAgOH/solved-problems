#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iterator>
#include <numeric>
const int maxw = 1e5+5;
vector<int> w;
bitset<maxw> dp;
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
    copy_n(istream_iterator<int>(cin), n, inserter(w, w.begin()));
    int sum = accumulate(w.begin(), w.end(), 0);
    for(auto i : w)
    {
        for(int j=sum;j>=0;j--)
            dp[j] = dp[j]|dp[abs(j-i)];
        for(int j=0;j<=sum-i;j++)
            dp[j] = dp[j]|dp[j+i];
        dp[i] = true;
    }
    cout<<dp.count()-dp[0]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
