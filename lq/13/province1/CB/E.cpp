#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
const int mod = 1e9+7;
typedef long long ll;
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
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i];
    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++) cin>>b[i];
    if(a.size()<b.size()) a.insert(a.begin(), b.size()-a.size(), 0);
    else if(b.size()<a.size()) b.insert(b.begin(), a.size()-b.size(), 0);
    ll ans = 0;
    for(size_t i=0;i<a.size();i++)
        ans = (ans*max({2, a[i]+1, b[i]+1})+a[i]-b[i]+mod)%mod;
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}