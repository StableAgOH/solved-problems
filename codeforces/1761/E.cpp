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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> G(n+1);
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<n;j++) if(s[j]=='1') G[i+1].push_back(j+1);
        }
        vector<int> fa(n+1);
        iota(fa.begin(), fa.end(), 0);
        function<int(int)> find = [&](int x) { return fa[x]==x?x:fa[x]=find(fa[x]); };
        int cnt = n;
        for(int u=1;u<=n;u++)
        {
            for(auto v : G[u])
            {
                int fu = find(u);
                int fv = find(v);
                if(fu==fv) continue;
                cnt--;
                fa[fu] = fv;
            }
        }
        if(cnt==1)
        {
            cout<<0<<'\n';
            continue;
        }
        unordered_map<int, vector<int>, hasher> con;
        for(int u=1;u<=n;u++) con[find(u)].push_back(u);
        vector<int> ans;
        vector<int> com;
        for(auto&& [k,s] : con)
        {
            if(s.size()==1)
            {
                ans.clear();
                ans.push_back(k);
                break;
            }
            int w = -1;
            for(auto u : s)
                if(G[u].size()!=s.size()-1)
                    if(w==-1||G[u].size()<G[w].size())
                        w = u;
            if(~w)
            {
                ans.clear();
                ans.push_back(w);
                break;
            }
            else com.push_back(k);
        }
        if(ans.empty())
        {
            if(com.size()==2)
            {
                if(con[com[0]].size()<con[com[1]].size()) ans = con[com[0]];
                else ans = con[com[1]];
            }
            else
            {
                ans.push_back(con[com[0]][0]);
                ans.push_back(con[com[1]][0]);
            }
        }
        #ifdef LOCAL
            sort(ans.begin(), ans.end());
        #endif
        cout<<ans.size()<<'\n';
        for(auto i : ans) cout<<i<<' ';
        cout<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
