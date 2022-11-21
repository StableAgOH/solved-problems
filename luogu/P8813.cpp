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
    const int limit = 1e9;
    int n,m;
    cin>>n>>m;
    if(n==1) cout<<1<<endl;
    else
    {
        bool flag = true;
        ll mul = 1;
        for(ll i=0;i<m;i++)
        {
            mul *= n;
            if(mul>limit)
            {
                flag = false;
                break;
            }
        }
        if(flag) cout<<mul<<endl;
        else cout<<-1<<endl;
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
