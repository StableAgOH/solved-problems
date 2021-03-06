#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <numeric>
#include <algorithm>
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
    sort(v.begin()+1, v.end());
    vector<ll> pre(n+1);
    partial_sum(v.begin(), v.end(), pre.begin());
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        cout<<pre[n-x+y]-pre[n-x]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
