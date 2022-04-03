#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <stack>
const int maxn = 2e5+5;
struct E { int to,next; } Edge[maxn];
int tot,Head[maxn];
inline void AddEdge(int u,int v)
{
    Edge[tot]={v,Head[u]};
    Head[u]=tot++;
}
stack<int> st;
int tim,ans=23333333;
int dfn[maxn],low[maxn];
bool vis[maxn];
void tarjan(int u)
{
    dfn[u]=low[u]=++tim;
    st.push(u);
    vis[u]=true;
    for(int i=Head[u];~i;i=Edge[i].next)
    {
        int v = Edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        int cnt=0;
        while(true)
        {
            int tmp = st.top();
            st.pop();
            vis[tmp]=false;
            cnt++;
            if(u==tmp) break;
        }
        if(cnt>1) ans=min(ans,cnt);
    }
}
#include <cstring>
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
    memset(Head,-1,sizeof(Head));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int v;
        cin>>v;
        AddEdge(i,v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
