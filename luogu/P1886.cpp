#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <functional>
#include <deque>
const int maxn = 1e6+5;
int n,k;
int a[maxn];
deque<int> q;
void solve(function<bool(int,int)> rule)
{
    q.clear();
    for(int i=1;i<=n;i++)
    {
        if(!q.empty()&&q.front()+k==i) q.pop_front();
        while(!q.empty()&&rule(a[i],a[q.back()]))
            q.pop_back();
        q.push_back(i);
        if(i>=k) cout<<a[q.front()]<<' ';
    }
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
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    solve([](int a,int b) { return a<b; });
    cout<<endl;
    solve([](int a,int b) { return a>b; });
    cout<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
