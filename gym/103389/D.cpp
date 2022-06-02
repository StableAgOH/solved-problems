#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
struct C { bool operator()(const pii& p1, const pii& p2) const { return max(p1.first, p1.second)<max(p2.first, p2.second); } };
priority_queue<pii, vector<pii>, C> pq; 
int main()
{
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int n;
    cin>>n;
    int last = -1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(i!=1) pq.emplace(last, x);
        last = x;
    }
    long long ans = 0;
    for(int i=1;i<n;i++)
    {
        auto p = pq.top();
        pq.pop();
        ans += max(p.first, p.second);
    }
    cout<<ans<<endl;
    return 0;    
}