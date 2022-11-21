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
        ll n,e,d;
        cin>>n>>e>>d;
        ll a = 1;
        ll b = e*d-n-2;
        ll c = n;
        ll delta = b*b-4*a*c;
        if(delta<0) cout<<"NO"<<'\n';
        else
        {
            ll s = sqrtl(delta);
            if(s*s!=delta) cout<<"NO"<<'\n';
            else
            {
                int o = (b&1)+(s&1);
                if(o==1) cout<<"NO"<<'\n';
                else
                {
                    ll p = (-b-s)/2;
                    ll q = (-b+s)/2;
                    if(p<0||q<0) cout<<"NO"<<'\n';
                    else cout<<p<<' '<<q<<'\n';
                }
            }
        }
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
