#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <climits>
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
    int mx = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mx = max(mx, x);
    }
    cout<<mx<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
