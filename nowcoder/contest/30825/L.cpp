#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e5+5;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        int cnt1=0, cnt2=0;
        int m = n;
        while(n)
        {
            if(n%x==1) cnt1++;
            n/=x;
        }
        while(m)
        {
            if(m%y==1) cnt2++;
            m/=y;
        }
        if(cnt1>cnt2) cout<<">"<<endl;
        else if(cnt1<cnt2) cout<<"<"<<endl;
        else cout<<"="<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
