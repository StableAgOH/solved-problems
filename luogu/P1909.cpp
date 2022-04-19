#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    int ans = 0x3f3f3f3f;
    for(int i=0;i<3;i++)
    {
        int a,b;
        cin>>a>>b;
        int tmp = ceil(1.0*n/a);
        ans = min(ans,tmp*b);
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
