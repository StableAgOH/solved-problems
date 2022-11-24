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
    int n;
    cin>>n;
    int cnt = 0;
    vector<vector<int>> ans;
    vector<int> v(n);
    function<bool(int,int)> check = [&](int r,int c)
    {
        for(int i=0;i<r;i++) if(v[i]==c||v[i]==c-(r-i)||v[i]==c+(r-i)) return false;
        return true;
    };
    function<void(int)> dfs = [&](int r)
    {
        if(r==n)
        {
            if(cnt++<3) ans.emplace_back(v);
            return;
        }
        for(int c=0;c<n;c++)
        {
            if(!check(r,c)) continue;
            v[r] = c;
            dfs(r+1);
        }
    };
    dfs(0);
    for(auto&& v : ans)
    {
        for(auto i : v) cout<<i+1<<' ';
        cout<<'\n';
    }
    cout<<cnt<<'\n';
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
