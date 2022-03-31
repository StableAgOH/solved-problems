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
        int n,h;
        cin>>n>>h;
        int mx1=0, mx2=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x>mx1) mx2=mx1, mx1=x;
            else if(x>mx2) mx2=x;
        }
        int cnt = (h/(mx1+mx2))<<1;
        h %= (mx1+mx2);
        if(h)
        {
            if(mx1>=h) cnt++;
            else cnt+=2;
        }
        cout<<cnt<<endl;
    }
    //======================================
    exit();
}