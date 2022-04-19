#include <iostream>
#include <chrono>
using namespace std;
//==========================================
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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int t = d-b;
    if(t<0)
    {
        t += 60;
        c--;
    }
    cout<<c-a<<' '<<t<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
