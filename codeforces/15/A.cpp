#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
//==========================================
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
#endif
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,t;
	cin>>n>>t;
    vector<pair<int,int>> v(n);
	for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    sort(v.begin(), v.end());
	int cnt = 0;
    for(int i=0;i<n-1;i++)
    {
        auto [a,b] = v[i];
        auto [p,q] = v[i+1];
        int o = 2*p-q-2*a-b;
        if(o>2*t) cnt++;
        if(o>=2*t) cnt++;
    }
    cout<<cnt+2<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
