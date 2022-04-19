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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int x;
    ll n;
    cin>>x>>n;
    ll sum = 0;
    for(int i=0;i<n;i++)
    {
        if(x==7) x = 1;
        else
        {
            if(x!=6) sum += 250;
            x++;
        }
    }
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
