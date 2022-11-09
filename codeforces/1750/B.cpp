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
        string s;
        cin>>s;
        ll x = count(s.begin(), s.end(), '0');
        ll y = count(s.begin(), s.end(), '1');
        ll mx = x*y;
        ll cnt = 0;
        char lst = s.front();
        for(char c : s)
        {
            if(c==lst) cnt++;
            else
            {
                mx = max(mx, cnt*cnt);
                lst = c;
                cnt = 1;
            }
        }
        mx = max(mx, cnt*cnt);
        cout<<mx<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
