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
        string a,b;
        bool first = true;
        for(auto c : s)
        {
            switch(c)
            {
            case '0':
                a.push_back('0');
                b.push_back('0');
                break;
            case '1':
                if(first)
                {
                    a.push_back('1');
                    b.push_back('0');
                    first = false;
                }
                else
                {
                    a.push_back('0');
                    b.push_back('1');
                }
                break;
            case '2':
                if(first)
                {
                    a.push_back('1');
                    b.push_back('1');
                }
                else
                {
                    a.push_back('0');
                    b.push_back('2');
                }
                break;
            }
        }
        cout<<a<<'\n'<<b<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
