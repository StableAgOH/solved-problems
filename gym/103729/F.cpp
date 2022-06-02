#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
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
    int n;
    cin>>n;
    if(n==1) cout<<1<<endl<<1<<endl;
    else if(n==2) cout<<2<<endl<<"1 1"<<endl;
    else
    {
        cout<<2*n-4<<endl;
        for(int i=2;i<=n-1;i++) cout<<i<<' ';
        for(int i=n-1;i>=2;i--) cout<<i<<' ';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}