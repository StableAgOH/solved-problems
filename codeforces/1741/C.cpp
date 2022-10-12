#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <functional>
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
        vector<ll> pre(n+1);
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            pre[i] = pre[i-1]+x;
        }
        int mn = n;
        for(int i=1;i<=n;i++)
        {
            int mx = i;
            auto lst = pre.begin();
            for(ll t=pre[i];;t+=pre[i])
            {
                auto it = lower_bound(pre.begin()+1, pre.end(), t);
                if(it==pre.end()||*it!=t) break;
                if(it==pre.end()-1)
                {
                    mx = max(mx, int(it-lst));
                    mn = min(mn, mx);
                    break;
                }
                mx = max(mx, int(it-lst));
                lst = it;
            }
        }
        cout<<mn<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
