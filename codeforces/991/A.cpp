#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e5 + 5;
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    int x = n-(a+b-c);
    if(x<1||x>n||c>a||c>b) cout<<-1<<endl;
    else cout<<x<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}