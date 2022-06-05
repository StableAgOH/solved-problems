#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <algorithm>
typedef long long ll;
typedef pair<int,int> pii;
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            v[i] -= x;
        }
        vector<pii> w;
        vector<vector<int>> e(n+1);
        for(int i=0;i<m;i++)
        {
            int l,r;
            cin>>l>>r;
            w.emplace_back(l,r);
            e[r].push_back(i);
            e[l-1].push_back(i);
        }
        partial_sum(v.begin(), v.end(), v.begin());
        vector<int> vis(m);
        queue<int> q;
        set<int> s;
        for(int i=0;i<=n;i++)
        {
            if(!v[i]) q.push(i);
            else s.insert(i);
        }
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            for(auto i : e[p]) if(++vis[i]==2)
            {
                auto [l,r] = w[i];
                auto itl = s.lower_bound(l);
                auto itr = s.upper_bound(r);
                for_each(itl, itr, [&q](int x) { q.push(x); });
                s.erase(itl, itr);
            }
        }
        cout<<(s.empty()?"YES":"NO")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
