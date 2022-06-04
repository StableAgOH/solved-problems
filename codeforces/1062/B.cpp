#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
vector<int> divide(int x)
{
    if(x==1) return vector<int>(1,1);
    vector<int> ret;
    for(int i=2;;i++)
    {
        if(x%i==0)
        {
            ret.push_back(i);
            x/=i;
            i--;
            if(x==1) break;
        }
    }
    return ret;
}
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    vector<int> v = divide(n);
    map<int, int> m;
    for(auto i : v)
        m[i]++;
    int mx = -1;
    int mn = 0x3f3f3f3f;
    long long ans = 1;
    for(auto p : m)
    {
        mn = min(mn, p.second);
        mx = max(mx, p.second);
        ans *= p.first;
    }
    int k = (int)(ceil(log2(mx)));
    if(!(mx==mn&&mx==1<<k)) k++;
    cout<<ans<<' '<<k<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}