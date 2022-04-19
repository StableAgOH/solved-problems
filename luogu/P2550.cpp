#include <iostream>
#include <chrono>
using namespace std;
//==========================================
int a[9], b[9];
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
    int n;
    cin>>n;
    for(int i=0;i<7;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        int cnt = 0;
        for(int j=0;j<7;j++)
        {
            int tmp;
            cin>>tmp;
            for(int k=0;k<7;k++)
                if(tmp==a[k]) cnt++;
        }
        b[cnt]++;
    }
    for(int i=7;i>0;i--) cout<<b[i]<<' ';
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
