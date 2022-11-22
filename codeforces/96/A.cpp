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
    string s;
    cin>>s;
    char lst = '$';
    int cnt = 0;
    bool flag = false;
    for(size_t i=0;i<s.length();i++)
    {
        if(s[i]==lst) cnt++;
        else
        {
            lst = s[i];
            if(cnt>=7) break;
            cnt = 1;
        }
    }
    if(cnt>=7) flag = true;
    cout<<(flag?"YES":"NO")<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
