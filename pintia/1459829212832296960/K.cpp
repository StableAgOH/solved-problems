#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <iomanip>
#include <numeric>
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
        vector<int> G[n+1];
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int tim = 0;
        vector<int> eln(n+1);
        function<void(int,int)> dfs = [&](int u,int f) {
            if(!eln[u]) eln[u] = tim;
            for(int v : G[u])
            {
                if(v==f) continue;
                ++tim;
                dfs(v,u);
                ++tim;
            }
        };
        dfs(1,0);
        cout<<fixed<<setprecision(10)<<accumulate(eln.begin(), eln.end(), 0LL)/(long double)(n-1)<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
