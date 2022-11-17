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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        int cnt = 0;
        int p = find(v.begin()+1, v.end(), 0)-v.begin();
        ll pre = 0;
        for(int i=1;i<p;i++) if(!(pre+=v[i])) cnt++;
        for(int i=p;i<=n;)
        {
            int j = find(v.begin()+i+1, v.end(), 0)-v.begin();
            map<ll,int> mp;
            pre = 0;
            int mx = 0;
            for(int k=i;k<j;k++) mp[pre+=v[k]]++;
            pre = 0;
            for(int k=i;k<j;k++) mx = max(mx, mp[pre+=v[k]]);
            cnt += mx;
            i = j;
        }
        cout<<cnt<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
