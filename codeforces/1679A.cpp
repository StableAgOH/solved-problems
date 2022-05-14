#include <iostream>
#include <chrono>
using namespace std;
//==========================================
typedef long long ll;
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
        ll n;
        cin>>n;
        if(n%2||n<4) cout<<-1<<endl;
        else
        {
            ll mx, mn;
            mx = n/4;
            if(n<6) mn = mx;
            else mn = n%6?n/6+1:n/6;
            cout<<mn<<' '<<mx<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}