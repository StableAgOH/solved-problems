#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
typedef long long ll;
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        if(x==7) cout<<2<<' '<<4<<' '<<1<<endl;
        else
        {
            int t = x/3;
            if(x%3==0)
            {
                cout<<t<<' '<<t+1<<' '<<t-1<<endl;
            }
            else if(x%3==1)
            {
                cout<<t+1<<' '<<t+2<<' '<<t-2<<endl;
            }
            else cout<<t+1<<' '<<t+2<<' '<<t-1<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
