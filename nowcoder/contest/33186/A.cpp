#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
#include <vector>
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> v;
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,r;
        cin>>x>>r;
        v.emplace_back(x-r, 1);
        v.emplace_back(x+r, -1);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    ll last = -1;
    ll ans = 0;
    bool first = true;
    for(auto&& i : v)
    {
        auto&& [x,f] = i;
        cnt += f;
        if(f==-1&&!cnt) last = x;
        else if(f==1&&cnt==1)
        {
            if(first) first = false;
            else ans += x - last;
        }
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
