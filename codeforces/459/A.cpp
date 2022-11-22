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
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2)
    {
        int p = y2-y1;
        cout<<x1+p<<' '<<y1<<' '<<x2+p<<' '<<y2<<'\n';
    }
    else if(y1==y2)
    {
        int p = x2-x1;
        cout<<x1<<' '<<y1+p<<' '<<x2<<' '<<y2+p<<'\n';
    }
    else if(abs(x2-x1)==abs(y2-y1)) cout<<x1<<' '<<y2<<' '<<x2<<' '<<y1<<'\n';
    else cout<<-1<<'\n';
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
