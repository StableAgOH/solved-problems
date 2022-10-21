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
        int n,m;
        cin>>n>>m;
        const int S = (n+1)*(m+1)+1;
        vector<string> grid(n+2);
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            s = '$'+s+'$';
            grid[i] = s;
        }
        vector<pair<int,int>> G[S];
        auto encode = [&](int x,int y) { return x*(m+1)+y; };
        auto decode = [&](int u) { return make_pair(u/(m+1), u%(m+1)); };
        auto clean = [&](int x,int y) { 
            if(x>1&&grid[x-1][y]=='#') return false;
            if(x<n&&grid[x+1][y]=='#') return false;
            if(y>1&&grid[x][y-1]=='#') return false;
            if(y<m&&grid[x][y+1]=='#') return false;
            return true;
        };
        auto add_edge = [&](int u,int v,int w) { G[u].emplace_back(v,w); };
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                auto t = encode(i,j);
                if(i!=1)
                {
                    if(j!=1&&clean(i-1,j-1)) add_edge(t,encode(i-1,j-1),grid[i-1][j-1]=='.');
                    if(j!=m&&clean(i-1,j+1)) add_edge(t,encode(i-1,j+1),grid[i-1][j+1]=='.');
                }
                if(i!=n)
                {
                    if(j!=1&&clean(i+1,j-1)) add_edge(t,encode(i+1,j-1),grid[i+1][j-1]=='.');
                    if(j!=m&&clean(i+1,j+1)) add_edge(t,encode(i+1,j+1),grid[i+1][j+1]=='.');
                }
            }
        }
        for(int i=1;i<=n;i++) if(clean(i,1)) add_edge(0,encode(i,1),grid[i][1]=='.');
        vector<bool> vis(S);
        vector<int> dis(S, 1e9);
        vector<int> pre(S);
        auto bfs = [&](int s) {
            deque<int> dq;
            dq.push_back(s);
            dis[s] = 0;
            while(!dq.empty())
            {
                int u = dq.front();
                dq.pop_front();
                if(vis[u]) continue;
                vis[u] = true;
                for(auto [v,w] : G[u])
                {
                    if(dis[u]+w<dis[v])
                    {
                        dis[v] = dis[u]+w;
                        pre[v] = u;
                        if(w) dq.push_back(v);
                        else dq.push_front(v);
                    }
                }
            }
        };
        bfs(0);
        int mn = 1e9;
        int u = -1;
        for(int i=1;i<=n;i++)
        {
            auto t = encode(i,m);
            if(dis[t]<mn)
            {
                mn = dis[t];
                u = t;
            }
        }
        if(mn==1e9) cout<<"NO"<<'\n';
        else
        {
            cout<<"YES"<<'\n';
            while(u)
            {
                auto [x,y] = decode(u);
                grid[x][y] = '#';
                u = pre[u];
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++) cout<<grid[i][j];
                cout<<'\n';
            }
        }
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
