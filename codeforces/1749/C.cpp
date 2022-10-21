#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/debug.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        multiset<int> s;
        for(int i=1;i<=n;i++) s.insert(v[i]);
        bool f = true;
        for(int k=n;k>=1;k--)
        {
            auto r = s;
            bool flag = true;
            for(int i=1;i<=k;i++)
            {
                auto it = r.upper_bound(k-i+1);
                if(it==r.begin())
                {
                    flag = false;
                    break;
                }
                --it;
                r.erase(it);
                if(i==k) continue;
                auto x = *r.begin();
                r.erase(r.find(x));
                r.insert(x+(k-i+1));
            }
            if(!flag) continue;
            cout<<k<<'\n';
            f = false;
            break;
        }
        if(f) cout<<0<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
