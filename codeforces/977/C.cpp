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
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(v.begin()+1, v.end());
    if(k==0) cout<<(v[1]==1?-1:1)<<endl;
    else if(k==n) cout<<v[n]<<endl;
    else
    {
        if(v[k]==v[k+1]) cout<<-1<<endl;
        else cout<<v[k]<<endl;
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
