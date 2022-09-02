#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5+5;
vector<int> G[maxn];
int S[maxn];
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
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int v;
            cin>>v;
            G[i].push_back(v);
        }
    }
    int cur = 1;
    for(int i=0;i<m;i++)
    {
        int opt,x;
        cin>>opt>>x;
        switch(opt)
        {
        case 0:
            cur = G[cur][x-1];
            break;
        case 1:
            S[x] = cur;
            cout<<cur<<'\n';
            break;
        case 2:
            cur = S[x];
            break;
        }
    }
    cout<<cur<<endl;
    return 0;
}
