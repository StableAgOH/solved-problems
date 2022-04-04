#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <iterator>
#include <algorithm>
const int maxn = 1e5+5;
vector<int> v;
bool mp[maxn];
int res[maxn];
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
    int n,k;
    cin>>n>>k;
    copy_n(istream_iterator<int>(cin), n, inserter(v, v.begin()));
    sort(v.begin(), v.end());
    res[0] = 1;
    mp[0] = true;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(mp[j]) break;
            if(v[j]-v[i]>=k)
            {
                mp[j] = true;
                res[j] = res[i]+1;
                break;
            }
        }
    }
    cout<<*max_element(res, res+maxn)<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
