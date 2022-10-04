#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <numeric>
typedef long long ll;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> a(n), b, c;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(a[i]) b.push_back(x);
            else c.push_back(x);
        }
        sort(b.begin(), b.end(), greater<>());
        sort(c.begin(), c.end(), greater<>());
        if(b.empty()) cout<<accumulate(c.begin(), c.end(), 0LL)<<endl;
        else if(c.empty()) cout<<accumulate(b.begin(), b.end(), 0LL)<<endl;
        else if(b.size()==c.size()) cout<<(accumulate(b.begin(), b.end(), 0LL)+accumulate(c.begin(), c.end(), 0LL))*2-min(b.back(), c.back())<<endl;
        else
        {
            auto mn = min(b.size(), c.size());
            ll x = accumulate(b.begin(), b.begin()+mn, 0LL)*2;
            ll y = accumulate(c.begin(), c.begin()+mn, 0LL)*2;
            ll z = accumulate(b.begin()+mn, b.end(), 0LL)+accumulate(c.begin()+mn, c.end(), 0LL);
            cout<<x+y+z<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
