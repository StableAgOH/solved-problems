#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
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
    int n,m;
    cin>>n>>m;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<ll> w(n+1);
    for(int i=2;i<=n;i++) if(v[i]<v[i-1]) w[i] = v[i-1]-v[i];
    vector<ll> pre(n+1);
    for(int i=2;i<=n;i++) pre[i] = pre[i-1]+w[i];
    vector<ll> u(n+1);
    for(int i=1;i<n;i++) if(v[i]<v[i+1]) u[i] = v[i]-v[i+1];
    vector<ll> pre2(n+2);
    for(int i=n-1;i>=1;i--) pre2[i] = pre2[i+1]+u[i];
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(x<y) cout<<pre[y]-pre[x]<<endl;
        else cout<<pre2[x]-pre2[y]<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}