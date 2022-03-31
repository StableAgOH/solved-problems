#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <queue>
#include <vector>
#include <map>
const int maxn = 2e5 + 5;
int a[maxn];
int dp[maxn];
int pre[maxn];
typedef pair<int,int> pii;
map<int, priority_queue<pii>> pq;
vector<int> v;
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
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        dp[i]=1;
    pq[a[1]].push({1, 1});
    for(int i=2;i<=n;i++)
    {
        if(pq[a[i]-1].empty())
        {
            pq[a[i]].push(pii(1, i));
            continue;
        }
        pii tmp = pq[a[i]-1].top();
        if(tmp.first+1>dp[i])
        {
            dp[i]=tmp.first+1;
            pre[i]=tmp.second;
        }
        pq[a[i]].push(pii(dp[i], i));
    }
    int mx = 0;
    int mi = 0;
    for(int i=1;i<=n;i++)
        cerr<<dp[i]<<' ';
    for(int i=1;i<=n;i++)
        if(dp[i]>mx)
            mx=dp[i], mi=i;
    cout<<mx<<endl;
    while(mi)
    {
        v.push_back(mi);
        mi = pre[mi];
    }
    for(auto it=v.rbegin(); it!=v.rend(); it++)
        cout<<*it<<" ";
    //======================================
end:
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}