#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <list>
#include <numeric>
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
    int n,m;
    cin>>n>>m;
    list<int> ls(n);
    iota(ls.begin(), ls.end(), 1);
    auto it = ls.begin();
    while(!ls.empty())
    {
        for(int i=1;i<m;i++)
        {
            ++it;
            if(it==ls.end()) it=ls.begin();
        }
        cout<<*it<<' ';
        ls.erase(it++);
        if(it==ls.end()) it=ls.begin();
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
