#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> fa(n+1);
    for(int i=1;i<n;i++) cin>>fa[i+1];
    vector<vector<int>> H(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        H[u].push_back(v);
        H[v].push_back(u);
    }
    vector<int> ans(n+1, INT_MAX);
    queue<int> q;
    q.push(1);
    ans[1] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : H[u])
        {
            function<int(int)> update = [&](int x)
            {
                if(x==1) return 1;
                if(ans[x]<ans[u]+1) return x;
                ans[x] = ans[u]+1;
                q.push(x);
                return fa[x]=update(fa[x]);
            };
            update(v);
        }
    }
    for(int i=2;i<=n;i++) cout<<(ans[i]==INT_MAX?-1:ans[i])<<' ';
    return 0;
}
