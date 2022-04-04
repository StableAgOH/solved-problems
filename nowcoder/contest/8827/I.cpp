#include <iostream>
#include <ctime>
using namespace std;
//==========================================
typedef long long ll;
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
    ll x,y,n;
    cin>>n>>x>>y;
    ll ans = 0;
    if(x+y<=n-1)
    {
        ll tmp = y*(y+1)/2+(2*y+x+3)*x/2;
        cout<<tmp<<endl;
        ans = tmp;
    }
    else
    {
        ll yxj = n*n-1;
        int a = n-1-x;
        int b = n-1-y;
        ll tmp = b*(b+1)/2+(2*b+a+3)*a/2;
        ll tmp2 = yxj - tmp;
        cout<< tmp2 <<endl;
        ans = tmp2;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
