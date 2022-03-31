#include <iostream>
#include <ctime>
using namespace std;
//==========================================
typedef long long ll;
ll solve(ll x,ll y,ll k)
{
    if(x>k||y>k) return -1;
    if((x+y)%2) return k-1;
    if((k-max(x,y))%2)
        return k-2;
    return k;
}
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
    int q;
    cin>>q;
    while(q--)
    {
        ll x,y,k;
        cin>>x>>y>>k;
        cout<<solve(x,y,k)<<endl;
    }
    //======================================
#ifdef LOCAL
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}