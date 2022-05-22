#include <iostream>
#include <chrono>
using namespace std;
//==========================================
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
    int q;
    cin>>q;
    while(q--)
    {
        int n,m;
        cin>>n>>m;
        if(n>=m) cout<<n-m<<'\n';
        else if(m%n==0) cout<<0<<'\n';
        else 
        {
            int ans = 0x3f3f3f3f;
            int p = m-1;
            for(int l=1,r;l<=n;l=r+1)
            {
                r = p/(p/l);
                ans = min(ans, p/l*l+n-m);
            }
            cout<<ans<<'\n';
        }
    }
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
