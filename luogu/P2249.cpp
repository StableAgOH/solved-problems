#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <iterator>
#include <vector>
#include <algorithm>
vector<int> v;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,m;
    cin>>n>>m;
    copy_n(istream_iterator<int>(cin), n, inserter(v,v.begin()));
    while(m--)
    {
        int x;
        cin>>x;
        auto it = lower_bound(v.begin(), v.end(), x);
        if(*it==x) cout<<it-v.begin()+1<<' ';
        else cout<<-1<<' ';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
