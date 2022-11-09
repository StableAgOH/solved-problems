#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        sort(v.begin()+1, v.end());
        unordered_map<ll,ll> mp;
        vector<ll> w = {ll(1e18)};
        for(int i=0;i<k;i++)
        {
            ll x,y;
            cin>>x>>y;
            if(y) mp[x] = y;
            else w.push_back(x);
        }
        sort(w.begin(), w.end());
        auto it = w.begin();
        ll p = 0;
        ll c = 0;
        ll sum = 0;
        for(int i=1;i<=n;i++)
        {
            while(*it<v[i])
            {
                p = *it+1;
                ++it;
                c = 0;
            }
            c++;
            if(mp.find(p)!=mp.end()&&c>mp[p])
            {
                p++;
                c = 1;
            }
            sum += v[i]-p;
        }
        cout<<(sum&1?"Pico":"FuuFuu")<<'\n';
    }
    return 0;
}
