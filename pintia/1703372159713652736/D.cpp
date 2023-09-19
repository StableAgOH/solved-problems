#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int maxn = 1e6+5;
int fa[maxn], siz[maxn];
int find(int x) { return x==fa[x]?x:fa[x]=find(fa[x]); };
void merge(int x,int y)
{
    int fx=find(x), fy=find(y);
    if(fx==fy) return;
    if(siz[fx]>siz[fy]) swap(fx,fy);
    fa[fx] = fy;
    siz[fy] += siz[fx];
};
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i] = i;
    for(int i=1;i<=n;i++) siz[i] = 1;
    vector<vector<int>> G(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        merge(u,v);
    }
    vector<vector<int>> con(n+1);
    for(int i=1;i<=n;i++) con[find(i)].push_back(i);
    bool flag = true;
    ll sum = 0;
    vector<int> szs;
    for(int i=1;i<=n;i++)
    {
        auto& v = con[i];
        if(v.empty()) continue;
        szs.push_back(siz[i]);
        for(auto j : v)
        {
            if((int)G[j].size()!=siz[i]-1)
            {
                sum += siz[i]-1-G[j].size();
                flag = false;
            }
        }
    }
    sort(szs.begin(), szs.end());
    if(flag)
    {
        ll x=szs[0], y=szs[1];
        cout<<x*y<<'\n';
    }
    else cout<<sum/2<<'\n';
    return 0;
}
