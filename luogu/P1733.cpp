#include <iostream>
#include <ctime>
using namespace std;
//==========================================
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
    int l=1, r=1e9;
    while(l<=r)
    {
        int m = (l+r)>>1;
        cout<<m<<endl;
        int res;
        cin>>res;
        if(res==1) r=m-1;
        else if(res==-1) l=m+1;
        else break;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
