#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <tuple>
#include <algorithm>
#include <climits>
const int maxn = 1e4+5;
const int maxm = 5e5+5;
typedef long long ll;
typedef tuple<int,int,int> tp3;
tp3 edge[maxm];
ll dis[maxn];
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,m,s;
    cin>>n>>m>>s;
    fill(dis+1, dis+1+n, INT_MAX);
    dis[s]=0;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge[i]={u,v,w};
    }
    for(int i=1;i<n;i++)
    {
        bool flag=true;
        for(int j=0;j<m;j++)
        {
            auto [u,v,w] = edge[j];
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                flag=false;
            }
        }
        if(flag) break;
    }
    for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
