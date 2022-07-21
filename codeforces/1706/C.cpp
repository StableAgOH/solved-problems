#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        vector<int> r(n+1);
        for(int i=2;i<n;i++) r[i] = max({v[i-1]-v[i]+1, v[i+1]-v[i]+1, 0});
        if(n&1)
        {
            ll sum = 0;
            for(int i=2;i<n;i+=2) sum += r[i];
            cout<<sum<<endl;
        }
        else
        {
            vector<ll> preodd(n+1), preeve(n+1);
            for(int i=2;i<n;i+=2) preeve[i] = preeve[i-2]+r[i];
            for(int i=3;i<n;i+=2) preodd[i] = preodd[i-2]+r[i];
            ll mn = 0x3f3f3f3f3f3f3f3f;
            for(int i=1;i<n;i+=2) mn = min(mn, preodd[n-1]-preodd[i]+preeve[i-1]);
            cout<<mn<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
