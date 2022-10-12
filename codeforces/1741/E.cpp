#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <functional>
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
        int n;
        cin>>n;
        vector<int> G[n+2];
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(i-x>=1) G[i-x].push_back(i+1);
            if(i+x+1<=n+1) G[i].push_back(i+x+1);
        }
        vector<bool> vis(n+2);
        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            for(auto v : G[u]) if(!vis[v]) dfs(v);
        };
        dfs(1);
        cout<<(vis[n+1]?"YES":"NO")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
