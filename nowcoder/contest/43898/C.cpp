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
const int maxn = 2e6+5;
struct E { int to,next; } Edge[maxn<<1];
int tot,Head[maxn];
void AddEdge(int u,int v) { Edge[tot]={v,Head[u]}; Head[u]=tot++; }
int d[maxn];
bool vis[maxn];
list<int> nodes[maxn];
queue<int> q;
pair<list<int>::iterator,int> pos[maxn];
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
    memset(Head, -1, sizeof(Head));
    int n,m;
    cin>>n>>m;
    n *= 2;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        AddEdge(u,v);
        AddEdge(v,u);
        d[u]++; d[v]++;
    }
    for(int i=1;i<=n;i++)
    {
        nodes[d[i]].push_front(i);
        pos[i].first = nodes[d[i]].begin();
        pos[i].second = d[i];
    }
    for(int i=0;i<n;i++) if(nodes[i].size()>1) q.push(i);
    auto remove = [&](int u) {
        for(int i=Head[u];~i;i=Edge[i].next)
        {
            int v = Edge[i].to;
            if(vis[v]) continue;
            auto [it,d] = pos[v];
            nodes[d].erase(it);
            nodes[d-1].push_front(v);
            pos[v].first = nodes[d-1].begin();
            pos[v].second = d-1;
            if(nodes[d-1].size()>1) q.push(d-1);
        }
    };
    while(!q.empty())
    {
        int f = q.front();
        if(nodes[f].size()<4)
        {
            q.pop();
            if(nodes[f].size()<2) continue;
        }
        auto u1 = nodes[f].front();
        nodes[f].pop_front();
        auto u2 = nodes[f].front();
        nodes[f].pop_front();
        vis[u1] = vis[u2] = true;
        cout<<u1<<' '<<u2<<'\n';
        remove(u1);
        remove(u2);
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
