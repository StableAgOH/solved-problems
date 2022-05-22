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
    ll sum1=0, sum2=0;
    for(int i=0;i<5;i++)
    {
        int x;
        cin>>x;
        sum1 += x;
    }
    for(int i=0;i<5;i++)
    {
        int x;
        cin>>x;
        sum2 += x;
    }
    if(sum1>=sum2) cout<<"Blue"<<endl;
    else cout<<"Red"<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
