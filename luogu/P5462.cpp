#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <list>
const int maxn = 1e5+5;
list<int> ls;
list<int>::iterator pos[maxn];
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
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ls.push_back(x);
        pos[x] = --ls.end();
    }
    for(int i=n;i>=1;i--)
    {
        auto s = pos[i], f = s++;
        if(f!=ls.end()&&s!=ls.end())
        {
            cout<<i<<' '<<*s<<' ';
            pos[i] = pos[*s] = ls.end();
            ls.erase(f); ls.erase(s);
        }
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
