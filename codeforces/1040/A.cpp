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
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> v(n);
    int sum = 0;
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n/2;i++)
    {
        int p = v[i];
        int q = v[n-i-1];
        debug(p, q);
        if(p==2&&q==2) sum += min(a,b)*2;
        else if(p==q) continue;
        else if(p==2) sum += q?b:a;
        else if(q==2) sum += p?b:a;
        else
        {
            sum = -1;
            break;
        }
    }
    if(~sum&&(n&1)&&v[n/2]==2) sum += min(a,b);
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
