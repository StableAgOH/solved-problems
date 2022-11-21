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
    int n,p;
    cin>>n>>p;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    reverse(v.begin(), v.end());
    ll cnt = 0;
    ll sum = 0;
    for(auto&& s : v)
    {
        if(s=="half")
        {
            sum += cnt*p;
            cnt *= 2;
        }
        else
        {
            sum += cnt*p+p/2;
            cnt = cnt*2+1;
        }
    }
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
