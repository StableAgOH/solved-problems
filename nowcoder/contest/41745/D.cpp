#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
typedef long long ll;
vector<ll> v[16];
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
    for(int w=0;w<=15;w++)
    {
        for(int i=1;i<=9;i++)
        {
            ll x = i;
            for(int j=1;j<17;j++)
            {
                int t = x%10^w;
                if(t>=10) break;
                x = x*10+t;
                v[w].push_back(x);
            }
        }
    }
    for(int w=0;w<=15;w++) sort(v[w].begin(), v[w].end());
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll l,r,w;
        cin>>l>>r>>w;
        auto itr = upper_bound(v[w].begin(), v[w].end(), r);
        auto itl = lower_bound(v[w].begin(), v[w].end(), l);
        cout<<itr-itl<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
