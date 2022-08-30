#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
typedef long long ll;
vector<int> v;
int getid(int x) { return lower_bound(v.begin(), v.end(), x)-v.begin()+1; }
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> w;
    for(int i=0;i<n;i++)
    {
        int s,t;
        cin>>s>>t;
        v.push_back(s), v.push_back(t);
        w.emplace_back(s,t);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int r = v.size();
    vector<int> f(r+1), g(r+1);
    for(auto [s,t] : w)
    {
        s=getid(s), t=getid(t);
        if(s<t) f[s]++, f[t]--;
        else g[t]++, g[s]--;
    }
    partial_sum(f.begin(), f.end(), f.begin());
    partial_sum(g.begin(), g.end(), g.begin());
    vector<ll> c(r+1);
    for(int i=1;i<r;i++) c[i] = int(ceil(max(f[i],g[i])/double(m)));
    ll mx = 0;
    ll sum = 0;
    for(int i=r-1;i>=1;i--)
    {
        mx = max(mx, c[i]);
        sum += mx*(v[i]-v[i-1]);
    }
    sum += mx*(v[0]-1);
    cout<<sum*2<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
