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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        if(accumulate(v.begin(), v.end(), 0)&1) cout<<-1<<'\n';
        else
        {
            vector<int> res = {-1};
            int last = -1;
            for(int i=0;i<n;i++) if(v[i])
            {
                if(~last)
                {
                    int l = i-last+1;
                    if(l&1)
                    {
                        if(v[i]==v[last]) res.push_back(last), res.push_back(i);
                        else res.push_back(i);
                    }
                    else
                    {
                        if(v[i]==v[last]) res.push_back(i);
                        else res.push_back(i-1), res.push_back(i);
                    }
                    last = -1;
                }
                else
                {
                    res.push_back(i-1);
                    last = i;
                }
            }
            res.erase(unique(res.begin(), res.end()), res.end());
            if(!v[n-1]) res.push_back(n-1);
            cout<<res.size()-1<<'\n';
            for(size_t i=1;i<res.size();i++) cout<<res[i-1]+2<<' '<<res[i]+1<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
