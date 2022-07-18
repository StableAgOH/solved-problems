#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
#include <string>
#include <unordered_map>
const int mod = 1e9+7;
typedef long long ll;
ll qpow(ll a,ll k,ll p)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%p)
        if(k&1) res=res*a%p;
    return res;
}
ll inv[130];
ll E[125][15];
unordered_map<string, int> mp;
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
    for(int i=1;i<=123;i++) inv[i] = qpow(i, mod-2, mod);
    int t;
    cin>>t;
    for(int _t=1;_t<=t;_t++)
    {
        memset(E, 0, sizeof(E));
        mp.clear();
        string s;
        cin>>s;
        for(int i=0;i<13;i++) mp[s.substr(i<<1, 2)]++;
        int q = 0;
        for(auto&& [k,v] : mp) if(v==1) q++;
        for(ll i=1;i<=123;i++)
        {
            for(ll j=1;j<=q;j++)
            {
                if(i<3*j) continue;
                E[i][j] = (i-3*j)*inv[i]%mod*E[i-1][j]%mod+1;
                if(j>2) E[i][j] = (E[i][j]+3*j*inv[i]%mod*E[i-1][j-2]%mod)%mod;
            }
        }
        cout<<"Case #"<<_t<<": "<<E[123][q]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
