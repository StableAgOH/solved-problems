#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
typedef pair<int,int> pii;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    __red(argc, argv);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> rbt;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        rbt.insert(make_pair(x,i));
    }
    int ans = 0;
    int last = 0;
    for(int i=1;i<=m;i++)
    {
        int opt,x;
        cin>>opt>>x;
        x ^= last;
        switch(opt)
        {
        case 1: // insert
            rbt.insert(make_pair(x,i+n));
            break;
        case 2: // remove
            rbt.erase(rbt.lower_bound(make_pair(x,0)));
            break;
        case 3: // query order(1-index) by number
            ans ^= (last=(rbt.order_of_key(make_pair(x,0))+1));
            break;
        case 4: // query number by order(1-index)
            ans ^= (last=(rbt.find_by_order(x-1)->first));
            break;
        case 5: // query prev
            ans ^= (last=(rbt.find_by_order(rbt.order_of_key(make_pair(x,0))-1)->first));
            break;
        case 6: // query next
            ans ^= (last=(rbt.find_by_order(rbt.order_of_key(make_pair(x+1,0)))->first));
            break;
        }
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
