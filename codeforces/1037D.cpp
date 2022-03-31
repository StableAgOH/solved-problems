#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <set>
#include <vector>
#include <queue>
const int maxn = 2e5 + 5;
vector<set<int>> G(maxn);
bool vis[maxn];
vector<int> seq;
bool judge()
{
    if(seq[0]!=1) return false;
    int cnt = 1;
    static queue<int> q;
    q.push(1);
    vis[1]=true;
    auto it = seq.begin()+1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        while(G[u].find(*it)!=G[u].end())
        {
            vis[*it]=true;
            q.push(*it);
            cnt++;
            ++it;
        }
    }
    if(cnt==seq.size()) return true;
    return false;
}
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].insert(v);
        G[v].insert(u);
    }
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        seq.push_back(tmp);
    }
    cout<<(judge()?"Yes":"No")<<endl;
    //======================================
#ifdef LOCAL
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}