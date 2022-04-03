#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <algorithm>
#include <vector>
const int maxn = 2e5+5;
vector<int> v;
vector<vector<int>> G(maxn);
int a[maxn];
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
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        int tmp = it-v.begin();
        for(int x : G[i])
            if(a[x]<a[i])
                tmp--;
        cout<<tmp<<" ";
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}