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
    int t;
    cin>>t;
    while(t--)
    {
        ll n,p;
        cin>>n>>p;
        if(p==1)
        {
            cout<<0<<'\n';
            continue;
        }
        ll tmp = n/p;
        int flag = -1;
        while(tmp)
        {
            n += flag*tmp;
            flag *= -1;
            tmp /= p;
        }
        cout<<n<<'\n';
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}