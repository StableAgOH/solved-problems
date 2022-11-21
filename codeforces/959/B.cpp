#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    __red(argc, argv);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,k,m;
    cin>>n>>k>>m;
    map<string,int> mp;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        mp[s] = i;
    }
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=0;i<k;i++)
    {
        int p;
        cin>>p;
        vector<int> g(p);
        ll mn = 0x3f3f3f3f;
        for(int j=0;j<p;j++)
        {
            cin>>g[j];
            mn = min(mn, v[g[j]]);
        }
        for(auto j : g) v[j] = mn;
    }
    ll sum = 0;
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        sum += v[mp[s]];
    }
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
