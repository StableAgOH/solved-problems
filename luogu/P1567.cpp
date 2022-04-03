#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <iterator>
#include <algorithm>
vector<int> v;
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
    copy_n(istream_iterator<int>(cin), n, inserter(v, v.begin()));
    int ans=1, cnt=1;
    for(auto it=v.begin()+1; it!=v.end(); ++it)
    {
        if(*it>*(it-1)) cnt++;
        else
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    cout<<max(ans, cnt)<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
