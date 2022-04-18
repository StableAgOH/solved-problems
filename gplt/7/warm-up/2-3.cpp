#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200;
int mid[maxn], post[maxn];
struct T { int l,r; } tree[maxn];
void dfs(int& u,int l,int r,int L,int R)
{
    if(l>r) return;
    u = post[R];
    if(l==r) return;
    int p;
    for(int i=l;i<=r;i++) if(mid[i]==u) p = i;
    dfs(tree[u].l, l, p-1, L, L+p-l-1);
    dfs(tree[u].r, p+1, r, L+p-l, R-1);
}
int ll[maxn], rr[maxn];
void dfs1(int u, int dep=1)
{
    if(!u) return;
    if(!ll[dep]) ll[dep] = u;
    dfs1(tree[u].l, dep+1);
    dfs1(tree[u].r, dep+1);
}
void dfs2(int u, int dep=1)
{
    if(!u) return;
    if(!rr[dep]) rr[dep] = u;
    dfs2(tree[u].r, dep+1);
    dfs2(tree[u].l, dep+1);
}
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>mid[i];
    for(int i=1;i<=n;i++) cin>>post[i];
    dfs(tree[0].l, 1, n, 1, n);
    dfs1(post[n]), dfs2(post[n]);
    vector<int> v1, v2;
    for(int i=1;rr[i];i++) v1.push_back(rr[i]);
    for(int i=1;ll[i];i++) v2.push_back(ll[i]);
    cout<<"R: ";
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i];
        if(i!=v1.size()-1) cout<<' ';
    }
    cout<<endl;
    cout<<"L: ";
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i];
        if(i!=v2.size()-1) cout<<' ';
    }
    return 0;
}
