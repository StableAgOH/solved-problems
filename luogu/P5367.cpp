#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
const int maxn = 1e6+5;
const int mod = 998244353;
typedef long long ll;
int n;
ll c[maxn];
int lowbit(int x) { return x&-x; }
void modify(int p,int x) { for(int i=p;i<=n;i+=lowbit(i)) c[i] += x; }
int query(int p)
{
    ll sum = 0;
    for(int i=p;i;i-=lowbit(i)) sum += c[i];
    return sum;
}
ll fac[maxn];
ll cantor(const vector<int>& v)
{
    fac[0] = 1;
    for(int i=1;i<=n;i++)
    {
        fac[i] = fac[i-1]*i%mod;
        modify(i, 1);
    }
    ll sum = 1;
    for(int i=1;i<=n;i++)
    {
        modify(v[i-1], -1);
        sum = (sum+fac[n-i]*query(v[i-1]))%mod;
    }
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
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<cantor(v)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}