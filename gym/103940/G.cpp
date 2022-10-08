#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e6+5;
int d[maxn], v[maxn];
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
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) cin>>d[i];
    for(int i=1;i<=n;i++) cin>>v[i];
    int l=1, r=n;
    while(l<r)
    {
        if(!v[l]&&!v[r])
        {
            if(l+1==r) break;
            int t = min(d[l+1], d[r]);
            d[l+1] -= t;
            d[r] -= t;
            if(!d[l+1]) l++;
            if(!d[r]) r--;
        }
        else if(!v[l])
        {
            int t = min(v[r], d[l+1]);
            v[r] -= t;
            d[l+1] -= t;
            if(!d[l+1]) l++;
        }
        else if(!v[r])
        {
            int t = min(d[r], v[l]);
            d[r] -= t;
            v[l] -= t;
            if(!d[r]) r--;
        }
        else
        {
            int t = min(v[l], v[r]);
            v[l] -= t;
            v[r] -= t;
        }
    }
    if(l==r) cout<<min(v[l], v[r])<<endl;
    else cout<<0<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
