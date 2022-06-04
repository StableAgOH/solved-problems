#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
const int maxn = 1e5+5;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int mn=0x3f3f3f3f;
        int mx=0xcfcfcfcf;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            mn=min(mn, x);
            mx=max(mx, x);
        }
        if(mx-mn>k<<1) cout<<-1<<endl;
        else cout<<mn+k<<endl;
    }
    //======================================
    exit();
}