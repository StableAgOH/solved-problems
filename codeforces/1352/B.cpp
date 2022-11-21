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
        int n,k;
        cin>>n>>k;
        if(k>n) cout<<"NO"<<'\n';
        else
        {
            bool b = n&1;
            bool c = k&1;
            if(b)
            {
                if(c)
                {
                    if(n<k) cout<<"NO"<<'\n';
                    else
                    {
                        cout<<"YES"<<'\n';
                        for(int i=1;i<k;i++) cout<<1<<' ';
                        cout<<n-k+1<<'\n';
                    }
                }
                else cout<<"NO"<<'\n';
            }
            else
            {
                if(c)
                {
                    if(n<2*k) cout<<"NO"<<'\n';
                    else
                    {
                        cout<<"YES"<<'\n';
                        for(int i=1;i<k;i++) cout<<2<<' ';
                        cout<<n-2*k+2<<'\n';
                    }
                }
                else
                {
                    cout<<"YES"<<'\n';
                    for(int i=1;i<k;i++) cout<<1<<' ';
                    cout<<n-k+1<<'\n';
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
