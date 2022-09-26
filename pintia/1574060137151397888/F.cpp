#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        ll k,u,v;
        cin>>k>>u>>v;
        vector<ll> p = {1};
        __int128_t x = k+1;
        while(x<=max(u,v))
        {
            p.push_back(x);
            x *= k+1;
        }
        while(u!=v)
        {
            if(u<v) swap(u,v);
            auto it = lower_bound(p.begin(), p.end(), u);
            --it;
            u = (u-1-*it)/k+1;
        }
        cout<<u<<'\n';
    }
    return 0;
}
