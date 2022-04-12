#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <iterator>
#include <algorithm>
typedef long long ll;
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
    int n,m;
    cin>>n>>m;
    ll sum = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        sum += x;
    }
    while(m--)
    {
        int l,r,z;
        cin>>l>>r>>z;
        sum += (ll)(r-l+1)*z;
        cout<<sum*(n*2-1)<<'\n';
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
