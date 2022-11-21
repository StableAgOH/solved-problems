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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(), v.end());
        if(n==2)
        {
            for(int i=0;i<n;i++) cout<<v[i]<<' ';
            cout<<'\n';
            continue;
        }
        int p = -1;
        int mn = 1e9;
        for(int i=1;i<n;i++)
        {
            if(v[i]-v[i-1]<mn)
            {
                mn = v[i]-v[i-1];
                p = i;
            }
        }
        for(int i=p;i<n;i++) cout<<v[i]<<' ';
        for(int i=0;i<p;i++) cout<<v[i]<<' ';
        cout<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
