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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,k;
    cin>>n>>k;
    int a=0, b=0;
    double A,B;
    for(int i=1;i<=n;i++)
    {
        if(i%k)
        {
            B += i;
            b++;
        }
        else
        {
            A += i;
            a++;
        }
    }
    cout<<fixed<<setprecision(1)<<A/a<<' '<<B/b<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
