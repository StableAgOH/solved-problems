#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
struct hasher
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x^(x>>30))*0xbf58476d1ce4e5b9;
        x = (x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const 
    {
        static const uint64_t fix = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+fix);
    }
};
//==========================================
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
#endif
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        vector<bool> vis(55);
        int mx = 0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            vis[x] = true;
            mx = max(x, mx);
        }
        int p = 0;
        for(int i=1;i<=mx;i++) if(!vis[i]) p += i;
        if(p>s) cout<<"NO"<<'\n';
        else
        {
            s -= p;
            int r = 0;
            for(int i=mx+1;;i++)
            {
                if(r==s)
                {
                    cout<<"YES"<<'\n';
                    break;
                }
                else if(r>s)
                {
                    cout<<"NO"<<'\n';
                    break;
                }
                r += i;
            }
        }
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
