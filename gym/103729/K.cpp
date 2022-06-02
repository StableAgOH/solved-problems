#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <iomanip>
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        double n,c;
        cin>>n>>c;
        double ans;
        if(n>=1e7) ans = c+2.0;
        else if(n<=9800000) ans = c+(n-9500000)/300000;
        else ans = c+1+(n-9800000)/200000;
        cout<<fixed<<setprecision(7)<<max(0.0,ans)<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}