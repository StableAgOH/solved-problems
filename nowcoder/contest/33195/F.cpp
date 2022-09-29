#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <queue>
#include <vector>
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
        int n,m,s,e;
        cin>>n>>m>>s>>e;
        vector<int> G[n+1];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        queue<int> q;
        vector<bool> vis(n+1);
        vector<int> cnt(n+1);
        q.push(e);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(vis[u]) continue;
            vis[u] = true;
            for(auto v : G[u])
            {
                cnt[v]++;
                if(cnt[v]==2) q.push(v);
            }
        }
        cout<<(vis[s]?"Join Player":"Cut Player")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
