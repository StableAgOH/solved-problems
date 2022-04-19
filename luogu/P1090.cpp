#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
#include <queue>
#include <algorithm>
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n, sum=0;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pq.push(x);
    }
    for(int i=1;i<n;i++)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        pq.push(x+y);
        sum += x+y;
    }
    cout<<sum<<endl;
    //======================================
    exit();
}