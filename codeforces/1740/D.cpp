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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> v(k+1);
        for(int i=1;i<=k;i++) cin>>v[i];
        unordered_map<int,bool> mp;
        int p = n*m-3;
        for(int i=1;i<=min(p,k);i++) mp[v[i]] = true;
        bool flag = true;
        for(int i=k;i>=1;i--)
        {
            if(!mp[i])
            {
                flag = false;
                break;
            }
            if(p<k) mp[v[++p]] = true;
        }
        if(flag) cout<<"YA"<<'\n';
        else cout<<"TIDAK"<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
