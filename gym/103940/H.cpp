#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <numeric>
typedef long long ll;
int n,s;
int a[25];
ll dfs(ll x,ll y,ll m)
{
    if(m>s) return 0;
    if(x>n) return s/m;
    if(!y) return s/m;
    ll sum = 0;
    for(int i=x;i<=n-y+1;i++) sum += dfs(i+1,y-1,lcm(m,a[i]));
    return sum;
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
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll sum = 0;
    for(int i=1;i<=n;i++)
    {
        auto t = dfs(1,i,1);
        if(i&1) sum += t;
        else sum -= t;
    }
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
