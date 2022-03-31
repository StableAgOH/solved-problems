#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
typedef pair<int,int> pii;
vector<pii> v;
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
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        sum += x;
        v.emplace_back(x,y);
    }
    sort(v.begin(), v.end(), [](pii& x, pii& y) { return x.first+x.second<y.first+y.second; });
    int ans = 0xcfcfcfcf;
    for(int i=v.size()-1;i>=0;i--)
    {
        sum -= v[i].first;
        ans = max(sum-v[i].second, ans);
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}