#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
const int maxn = 1005;
const double eps = 1e-8;
typedef pair<int,double> pii;
int n,m;
vector<pii> G[maxn];
int cnt[maxn];
double dis[maxn];
bool spfa(double k)
{
    fill(dis+1, dis+1+n, 1e9);
    fill(cnt+1, cnt+1+n, 0);
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto&& [v,w] : G[u])
        {
            auto t = dis[u]+w-log(k);
            if(t<dis[v])
            {
                dis[v] = t;
                cnt[v] = cnt[u]+1;
                if(cnt[v]==n) return true;
                q.push(v);
            }
        }
    }
    return false;
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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        G[b].emplace_back(d, log(a)-log(c));
    }
    double l=0, r=1;
    while(r-l>eps)
    {
        double k = (l+r)/2;
        if(spfa(k)) r = k;
        else l = k;
    }
    cout<<fixed<<setprecision(10)<<l<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
