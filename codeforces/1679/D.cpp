#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
const int maxn = 2e5+5;
typedef long long ll;
int a[maxn];
struct E { int to,next; } Edge[maxn];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot] = {v,Head[u]};
    Head[u] = tot++;
}
int n;
ll k;
bool check(int m)
{
    vector<int> d(n+1);
    vector<bool> has(n+1);
    int c = 0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=m)
        {
            c++;
            has[i] = true;
        }
    }
    if(!c) return false;
    for(int u=1;u<=n;u++)
    {
        if(!has[u]) continue;
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(!has[v]) continue;
            d[v]++;
        }
    }
    queue<int> q;
    vector<bool> vis(n+1);
    vector<int> ord;
    for(int i=1;i<=n;i++) if(!d[i]&&has[i]) q.push(i);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        ord.push_back(u);
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(!has[v]) continue;
            if(!--d[v]) q.push(v);
        }
    }
    if(count(d.begin(), d.end(), 0)!=d.size()) return true;
    else
    {
        vector<int> dp(n+1);
        for(int i=0;i<ord.size();i++)
        {
            int u = ord[i];
            for(int i=Head[u];~i;i=Edge[i].next)
            {
                int v = Edge[i].to;
                if(!has[v]) continue;
                dp[v] = max(dp[v], dp[u]+1);
            }
        }
        return *max_element(dp.begin(), dp.end())>=k-1;
    }
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
    memset(Head, -1, sizeof(Head));
    int m;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v);
    }
    int l=1, r=1e9+1;
    while(l<r)
    {
        int m = (l+r)>>1;
        if(check(m)) r = m;
        else l = m+1;
    }
    cout<<(l>1e9?-1:l)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
