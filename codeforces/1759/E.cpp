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
        int n;
        ll h;
        cin>>n>>h;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            pq.push(x);
        }
        function<int(int,int,ll,int)> dfs = [&](int x,int y,ll h,int c)
        {
            queue<ll> q;
            while(!pq.empty())
            {
                auto u = pq.top();
                if(u<h)
                {
                    h += u/2;
                    c++;
                    pq.pop();
                    q.push(u);
                }
                else break;
            }
            int mx = c;
            if(x) mx = max(mx, dfs(x-1, y, h*3, c));
            if(y) mx = max(mx, dfs(x, y-1, h*2, c));
            while(!q.empty())
            {
                auto u = q.front();
                q.pop();
                pq.push(u);
            }
            return mx;
        };
        cout<<dfs(1, 2, h, 0)<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
