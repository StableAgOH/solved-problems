#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <stack>
const int maxn = 5e5+5;
struct E{ int to,next; }Edge[maxn<<1];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot]={v,Head[u]};
    Head[u] = tot++;
}
int fa[maxn];
long long con[maxn], sum[maxn];
string s;
stack<int> st;
void dfs(int u)
{
    int tmp = 0;
    if(s[u-1]==')')
    {
        if(!st.empty())
        {
            con[u]=con[fa[tmp=st.top()]] + 1;
            st.pop();
        }
    }
    else st.push(u);
    sum[u]=sum[fa[u]]+con[u];
    for(int i=Head[u];~i;i=Edge[i].next)
        dfs(Edge[i].to);
    if(tmp) st.push(tmp);
    else if(!st.empty()) st.pop();
}
#include <cstring>
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    memset(Head,-1,sizeof(Head));
    int n;
    cin>>n>>s;
    for(int i=2;i<=n;i++)
    {
        int f;
        cin>>f;
        AddEdge(f,i);
        fa[i] = f;
    }
    dfs(1);
    long long ans = 0;
    for(int i=1;i<=n;i++) ans ^= sum[i]*i;
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
