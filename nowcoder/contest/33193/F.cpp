#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <unordered_map>
typedef long long ll;
ll p,a,b,c;
ll f(ll x) { return (a*x%p*x%p+b*x%p+c)%p; }
ll calc(ll n,ll m,ll x)
{
    unordered_map<ll,int> mp;
    ll plen=0, len=0;
    for(int i=1;i<=n+m;i++)
    {
        x = f(x);
        if(mp[x])
        {
            plen = mp[x]-1;
            len = i-mp[x];
            break;
        }
        mp[x] = i;
    }
    if(!len||n<=plen||n+m<=plen+len) return 0;
    n -= plen;
    ll nl = n/len;
    if(!nl) return m>=len?n:n+m-len;
    else
    {
        if(m>=(nl+1)*len) return n;
        else if(m>=(nl*2+1)*len-n) return n+m-(nl+1)*len;
        else if(m>=nl*len) return nl*len;
        else return m;
    }
}
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
        ll n,m,x;
        cin>>n>>m>>p>>x>>a>>b>>c;
        cout<<calc(n,m,x)<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
