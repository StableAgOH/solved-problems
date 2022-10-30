#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/debug.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
class StringHash
{
private:
    int mod;
    vector<ll> ppow, hpre;
public:
    StringHash(const string& s, int p=114514, int mod=998244353)
    {
        this->mod = mod;
        this->ppow.push_back(1);
        this->hpre.push_back(0);
        for(size_t i=1;i<=s.length();i++)
        {
            this->ppow.push_back(this->ppow[i-1]*p%mod);
            this->hpre.push_back(hpre[i-1]*p%mod+s[i-1]%mod);
        }
    }
    int get(int l,int r)
    {
        if(l>r) return -1;
        return (hpre[r]-hpre[l-1]*this->ppow[r-l+1]%mod+mod)%mod;
    }
};
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    string s;
    cin>>s;
    StringHash h(s);
    int n = s.length();
    vector<bool> c(n+1);
    for(int i=1;i<=n/2;i++) if(h.get(1,i)==h.get(n-i+1,n)) c[i] = true;
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++) pre[i] = pre[i-1]+c[i];
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        int k = min(x-1, n-x);
        cout<<pre[k]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
