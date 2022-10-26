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
bool check(const vector<int>& v)
{
    auto n = v.size();
    if(n&1) return true;
    else
    {
        vector<vector<int>> s(3);
        for(auto i : v) s[i%3].push_back(i);
        if(all_of(s.begin(), s.end(), [](auto& v) { return v.size()%2==0; })) return false;
        if(s[0].size()%2==0) swap(s[0], s[2]);
        else if(s[1].size()%2==0) swap(s[1], s[2]);
        unordered_map<int,bool> mp;
        for(auto i : s[0]) mp[i] = true;
        for(auto i : s[1]) for(int j=i-2;j<=i+2;j++) if(j!=i&&mp.find(j)!=mp.end()) return false;
        vector<int> p,q;
        for(auto i : s[2]) for(int j=i-2;j<=i+2;j++) if(j!=i&&mp.find(j)!=mp.end()) { p.push_back(i); break; }
        if(p.empty()) return true;
        mp.clear();
        for(auto i : s[1]) mp[i] = true;
        for(auto i : s[2]) for(int j=i-2;j<=i+2;j++) if(j!=i&&mp.find(j)!=mp.end()) { q.push_back(i); break; }
        if(q.empty()) return true;
        return p.size()==1&&q.size()==1&&p.front()==q.front();
    }
}
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
        cout<<(check(v)?"His little girlfriend":"rqd")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
