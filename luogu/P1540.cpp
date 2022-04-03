#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <queue>
#include <set>
queue<int> q;
set<int> s;
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
    int m,n;
    cin>>m>>n;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(s.find(x)==s.end())
        {
            if(q.size()==m)
            {
                s.erase(q.front());
                q.pop();
            }
            q.push(x);
            s.insert(x);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
