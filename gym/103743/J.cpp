#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <unordered_map>
typedef unsigned long long ull;
unordered_map<ull,ull> dp;
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
    dp[0] = dp[1] = 1;
    for(ull i=2;i;i++)
    {
        ull r = i/2;
        if(i&1) dp[i] = dp[r]*dp[r];
        else dp[i] = dp[r-1]*dp[r]*2;
        ull t = 1ull<<63;
        while((t&i)==0) t>>=1;
        if(!dp[i])
        {
            if(i+(t-(i-t)-(i-t))<i) break;
            i += (t-(i-t)-(i-t))-2;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        ull x;
        cin>>x;
        cout<<(dp.find(x)==dp.end()?0:dp[x])<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
