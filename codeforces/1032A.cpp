#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <map>
#include <cmath>
map<int,int> m;
const int maxn = 1e5 + 5;
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
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        m[tmp]++;
    }
    int mx = 0xcfcfcfcf;
    for(auto i : m)
        mx = max(mx, i.second);
    int tmp = ceil((double)mx/k);
    cout<<m.size()*tmp*k-n<<endl;
    //======================================
#ifdef LOCAL
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}