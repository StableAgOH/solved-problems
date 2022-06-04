#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <deque>
#include <numeric>
typedef long long ll;
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#endif
#ifdef LOCAL
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        if(k>=n)
        {
            ll s = ((k-n)+(k-1))*n/2;
            cout<<accumulate(v.begin(), v.end(), 0LL)+s<<endl;
        }
        else 
        {
            ll y = accumulate(v.begin()+1, v.begin()+k+1, 0LL);
            ll mx = y;
            for(int i=k+1;i<=n;i++)
            {
                y -= v[i-k];
                y += v[i];
                mx = max(mx, y);
            }
            cout<<mx+k*(k-1)/2<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
