#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 300;
const int maxm = maxn*maxn;
typedef long long ll;
struct E { int to,w,next; } Edge[maxm<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v,int w)
{
    Edge[tot] = {v,w,Head[u]};
    Head[u] = tot++;
}
unordered_map<string, int> mp1;
unordered_map<int, string> mp2;
ll val[maxn];
ll dis[maxn], pre[maxn], cnt[maxn], sum[maxn], dep[maxn];
bool vis[maxn];
typedef pair<ll,int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    pq.emplace(0, s);
    cnt[s] = 1;
    dep[s] = 1;
    sum[s] = val[s];
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(dis[u]+Edge[i].w<dis[v])
            {
                dis[v] = dis[u] + Edge[i].w;
                pre[v] = u;
                cnt[v] = cnt[u];
                sum[v] = sum[u]+val[v];
                dep[v] = dep[u]+1;
                pq.emplace(dis[v], v);
            }
            else if(dis[u]+Edge[i].w==dis[v])
            {
                cnt[v] += cnt[u];
                if(dep[u]+1>dep[v])
                {
                    pre[v] = u;
                    sum[v] = sum[u]+val[v];
                    dep[v] = dep[u]+1;
                }
                else if(dep[u]+1==dep[v])
                {
                    if(sum[u]+val[v]>sum[v])
                    {
                        pre[v] = u;
                        sum[v] = sum[u]+val[v];
                        dep[v] = dep[u]+1;
                    }
                }
            }
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(Head, -1, sizeof(Head));
    int n,m;
    string s, t;
    cin>>n>>m>>s>>t;
    mp1[s] = 1;
    mp2[1] = s;
    for(int i=2;i<=n;i++)
    {
        string s;
        cin>>s>>val[i];
        mp1[s] = i;
        mp2[i] = s;
    }
    for(int i=0;i<m;i++)
    {
        string u,v;
        int w;
        cin>>u>>v>>w;
        AddEdge(mp1[u], mp1[v], w);
        AddEdge(mp1[v], mp1[u], w);
    }
    dijkstra(1);
    int cur = mp1[t];
    stack<int> st;
    while(cur)
    {
        st.push(cur);
        cur = pre[cur];
    }
    if(!st.empty())
    {
        cout<<mp2[st.top()];
        st.pop();
    }
    while(!st.empty())
    {
        cout<<"->"<<mp2[st.top()];
        st.pop();
    }
    cout<<endl;
    cout<<cnt[mp1[t]]<<' '<<dis[mp1[t]]<<' '<<sum[mp1[t]]<<endl;
    return 0;
}
