#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
const int maxn = 127;
bool G[maxn][maxn];
int d[maxn];
vector<char> ans;
char judgeeuler()
{
    int cnt = 0;
    char cmin = 127;
    for(char i='A';i<='z';i++)
        if(d[i]%2) cnt++, cmin = min(cmin, i);
    if(!cnt) return 0;
    else if(cnt==2) return cmin;
    else return -1;
}
void dfs(char u)
{
    for(char v='A';v<='z';v++) if(G[u][v])
    {
        G[u][v]=G[v][u]=false;
        dfs(v);
    }
    ans.push_back(u);
}
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
    int n;
    cin>>n;
    char cmin = 127;
    while(n--)
    {
        char u,v;
        cin>>u>>v;
        cmin = min(cmin, min(u,v));
        G[u][v]=G[v][u]=true;
        d[u]++; d[v]++;
    }
    char j = judgeeuler();
    if(~j)
    {
        dfs(j?j:cmin);
        for(auto it=ans.rbegin();it!=ans.rend();it++)
            cout<<*it;
    }
    else cout<<"No Solution\n";
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
