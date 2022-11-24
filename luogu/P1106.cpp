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
    string s;
    cin>>s;
    int k;
    cin>>k;
    k = s.length()-k;
    int p = 0;
    string r;
    for(int i=0;i<k;i++)
    {
        for(auto c='0';c<='9';c++)
        {
            auto ed = s.end()-(k-i-1);
            auto it = find(s.begin()+p, ed, c);
            if(it==ed) continue;
            int q = it-s.begin();
            r.push_back(s[q]);
            p = q+1;
            break;
        }
    }
    auto it = r.begin();
    while(*it=='0') ++it;
    r.erase(r.begin(), it);
    cout<<(r==""?"0":r)<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
