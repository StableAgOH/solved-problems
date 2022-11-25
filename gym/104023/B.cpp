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
struct hasher
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x^(x>>30))*0xbf58476d1ce4e5b9;
        x = (x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const 
    {
        static const uint64_t fix = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+fix);
    }
};
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
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    forward_list<pair<int,int>> ls = { { v[n],n } };
    unordered_map<int, vector<decltype(ls.begin())>, hasher> mp = { { v[n], { ls.begin() } } };
    auto remove = [&](int i) { mp[i].pop_back(); if(mp[i].empty()) mp.erase(i); };
    function<bool(int)> dfs = [&](int p)
    {
        if(!p)
        {
            int cnt = 0;
            vector<int> ans(n+1);
            for(auto [x,y] : ls)
            {
                cout<<x<<' ';
                ans[y] = ++cnt;
            }
            cout<<'\n';
            for(int i=1;i<n;i++) cout<<ans[i]<<'\n';
            return true;
        }
        int cnt = 0;
        while(p&&v[p]==v[p+1]+1)
        {
            ls.emplace_front(1, p--);
            mp[1].push_back(ls.begin());
            cnt++;
        }
        if(cnt)
        {
            if(dfs(p)) return true;
            while(cnt--)
            {
                remove(1);
                ls.pop_front();
            }
            return false;
        }
        vector<int> keys;
        transform(mp.begin(), mp.end(), back_inserter(keys), [](auto&& p) { return p.first; });
        for(auto k : keys)
        {
            for(int i=2;i*i<=k;i++)
            {
                if(k%i) continue;
                int j = k/i;
                if(k-(i+j)!=v[p+1]-v[p]) continue;
                auto it = mp[k].back();
                remove(k);
                auto jt = ls.emplace_after(it, j, it->second);
                *it = { i,p };
                mp[i].push_back(it);
                mp[j].push_back(jt);
                if(dfs(p-1)) return true;
                remove(i);
                remove(j);
                *it = { k, jt->second };
                ls.erase_after(it);
                mp[k].push_back(it);
            }
        }
        return false;
    };
    if(!dfs(n-1)) cout<<-1<<'\n';
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
