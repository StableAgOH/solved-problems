#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    __red(argc, argv);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<ll>> v(n+1, vector<ll>(m+1));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>v[i][j];
        ll sum = 0;
        for(int i=1;i<=n/2;i++)
        {
            for(int j=1;j<=m/2;j++)
            {
                ll a = v[i][j];
                ll b = v[n-i+1][j];
                ll c = v[i][m-j+1];
                ll d = v[n-i+1][m-j+1];
                ll p = (a+b+c+d)/4;
                ll q = p+1;
                sum += min({
                    abs(a-a)+abs(b-a)+abs(c-a)+abs(d-a),
                    abs(a-b)+abs(b-b)+abs(c-b)+abs(d-b),
                    abs(a-c)+abs(b-c)+abs(c-c)+abs(d-c),
                    abs(a-d)+abs(b-d)+abs(c-d)+abs(d-d),
                    abs(a-p)+abs(b-p)+abs(c-p)+abs(d-p),
                    abs(a-q)+abs(b-q)+abs(c-q)+abs(d-q)
                });
            }
        }
        if(n&1)
        {
            int o = n/2+1;
            for(int i=1;i<=m/2;i++)
            {
                ll a = v[o][i];
                ll b = v[o][m-i+1];
                ll p = (a+b)/2;
                sum += abs(a-p)+abs(b-p);
            }
        }
        if(m&1)
        {
            int o = m/2+1;
            for(int i=1;i<=n/2;i++)
            {
                ll a = v[i][o];
                ll b = v[n-i+1][o];
                ll p = (a+b)/2;
                sum += abs(a-p)+abs(b-p);
            }
        }
        cout<<sum<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
