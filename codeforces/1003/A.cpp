#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <map>
map<int,int> m;
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
    int mx = 0xcfcfcfcf;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        m[x]++;
        mx=max(mx, m[x]);
    }
    cout<<mx<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}