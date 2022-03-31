#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 3e6+5;
typedef long long ll;
ll inv[maxn];
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
    inv[1]=1;
    int n,p;
    cin>>n>>p;
    for(int i=2;i<=n;i++) inv[i]=(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=n;i++) cout<<inv[i]<<'\n';
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
