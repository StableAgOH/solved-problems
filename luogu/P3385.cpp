#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <tuple>
#include <vector>
#include <cstring>
const int maxn = 2e3+5;
const int INF = 0x3f3f3f3f;
typedef tuple<int,int,int> tp3;
inline int add(int a,int b) { return a==INF||b==INF?INF:a+b; }
vector<tp3> edge;
int dis[maxn];
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
    int t;
    cin>>t;
    while(t--)
    {
        edge.clear();
        memset(dis, 0x3f, sizeof(dis));
        dis[1]=0;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            edge.emplace_back(u,v,w);
            if(w>=0) edge.emplace_back(v,u,w);
        }
        for(int i=1;i<n;i++)
        {
            bool flag = true;
            for(auto [u,v,w] : edge)
            {
                if(add(dis[u], w)<dis[v])
                {
                    dis[v]=dis[u]+w;
                    flag = false;
                }
            }
            if(flag) break;
        }
        for(auto [u,v,w] : edge)
            if(add(dis[u],w)<dis[v])
                goto yes;
        cout<<"NO"<<endl;
        continue;
    yes:
        cout<<"YES"<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
