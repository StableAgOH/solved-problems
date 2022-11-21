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
    // i := (s div 50) mod 475
    // repeat 25 times:
    //     i := (i * 96 + 42) mod 475
    //     print (26 + i)
    auto f = [](int s)
    {
        vector<int> v;
        int i = (s/50)%475;
        for(int j=0;j<25;j++)
        {
            i = (i*96+42)%475;
            v.push_back(i+26);
        }
        return v;
    };
    int p,x,y;
    cin>>p>>x>>y;
    for(int s=y;;s++)
    {
        if(s%50!=x%50) continue;
        auto v = f(s);
        if(find(v.begin(), v.end(), p)!=v.end())
        {
            cout<<max(0, (s-x+50)/100)<<'\n';
            break;
        }
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
