#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <queue>
#include <vector>
const int maxn = 3005;
int n,m;
vector<int> G[maxn];
vector<int> dijkstra(int s)
{
    typedef pair<int,int> pii;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> dis(n+1);
    fill(dis.begin(), dis.end(), 0x3f3f3f3f);
    dis[s] = 0;
    vector<bool> vis(n+1);
    pq.emplace(0, s);
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int v : G[u])
        {
            if(dis[u]+1<dis[v])
            {
                dis[v] = dis[u]+1;
                pq.emplace(dis[v],v);
            }
        }
    }
    return dis;
}
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
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int s1,t1,s2,t2;
    cin>>s1>>t1>>s2>>t2;
    auto dis_1 = dijkstra(1);
    auto dis_s1 = dijkstra(s1);
    auto dis_s2 = dijkstra(s2);
    int mn = 1e9;
    for(int i=1;i<=n;i++)
    {
        if(dis_1[i]+dis_s1[i]>t1||dis_1[i]+dis_s2[i]>t2) continue;
        mn = min(mn, dis_1[i]+dis_s1[i]+dis_s2[i]);
    }
    cout<<(mn==1e9?-1:m-mn)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
