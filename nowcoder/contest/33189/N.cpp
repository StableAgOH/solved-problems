#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <bitset>
#include <vector>
#include <numeric>
typedef long long ll;
typedef bitset<15> bs;
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
    ll n;
    cin>>n;
    vector<int> c(20);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        bs b(x);
        for(int j=0;j<15;j++) if(b[j]) c[j]++;
    }
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        bs b;
        for(int j=0;j<15;j++)
        {
            if(c[j])
            {
                c[j]--;
                b[j] = 1;
            }
        }
        v.push_back(b.to_ulong());
    }
    ll s = accumulate(v.begin(), v.end(), 0LL);
    ll r = accumulate(v.begin(), v.end(), 0LL, [](ll x,int y) { return x+y*y; });
    ll x = n*r-s*s;
    ll y = n*n;
    ll g = gcd(x, y);
    x /= g;
    y /= g;
    cout<<x<<'/'<<y<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
