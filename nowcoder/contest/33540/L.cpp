#include <iostream>
#include <chrono>
using namespace std;
//==========================================
typedef long long ll;
inline ll s(ll a,ll b) { return a*(a+1)/2*b*(b+1)/2; }
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
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    if(n<m) swap(n,m);
    if(x<y) swap(x,y);
    ll a,b;
    if(n==x) cout<<s(n,m-y)<<endl;
    else if(m==x) cout<<s(m,n-y)<<endl;
    else if(m==y) cout<<s(m,n-x)<<endl;
    else
    {
        ll res = s(n,m-y)+s(m,n-x)-s(m-y,n-x);
        if(m>x) res = max(res, s(n,m-x)+s(m,n-y)-s(m-x,n-y));
        cout<<res<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
