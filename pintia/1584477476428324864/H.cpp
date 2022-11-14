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
    int n;
    cin>>n;
    string s;
    cin>>s;
    auto valid = [&](const string& s)
    {
        int pre = 0;
        for(auto c : s)
        {
            if(c=='(') pre++;
            else
            {
                pre--;
                if(pre<0) return false;
            }
        }
        return !pre;
    };
    auto b = valid(s);
    auto p = s.find(')');
    auto q = s.find_last_of('(');
    string u = s;
    if(p!=string::npos)
    {
        u[p] = '(';
        b |= valid(u);
    }
    string v = s;
    if(q!=string::npos)
    {
        v[q] = ')';
        b |= valid(v);
    }
    cout<<(b?"Yes":"No")<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
