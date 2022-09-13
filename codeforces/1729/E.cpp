#include <iostream>
#include <chrono>
using namespace std;
//==========================================
typedef long long ll;
inline ll query(ll u,ll v)
{
    cout<<"? "<<u<<' '<<v<<endl;
    ll n;
    cin>>n;
    if(!n) exit(233);
    return n;
}
inline void submit(ll x)
{
    cout<<"! "<<x<<endl;
    exit(0);
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
    for(int i=3;;i++)
    {
        auto x=query(1,i), y=query(i,1);
        if(x!=y) submit(x+y);   
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}