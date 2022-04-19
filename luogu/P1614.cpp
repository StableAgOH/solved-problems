#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
int a[maxn];
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
    int n,m;
    cin>>n>>m;
    if(!m) cout<<0<<endl;
    else
    {
        int tmp=0, mn=0x3f3f3f3f;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            tmp += a[i];
            if(i>=m-1)
            {
                mn = min(mn,tmp);
                tmp -= a[i-m+1];
            }
        }
        cout<<mn<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
