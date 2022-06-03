#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <numeric>
#include "agoh/lib/MonotonyStack.hpp"
#include "agoh/lib/SparseTable.hpp"
using namespace agoh;
typedef long long ll;
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#endif
#ifdef LOCAL
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
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
        vector<ll> v(n+2);
        for(int i=1;i<=n;i++) cin>>v[i];
        vector<ll> pre(n+2), suf(n+2);
        partial_sum(v.begin(), v.end(), pre.begin());
        partial_sum(v.rbegin(), v.rend(), suf.rbegin());
        auto msl = MonotonyStack<int, greater_equal<int>>(v.begin()+1, v.end()-1);
        auto msr = MonotonyStack<int, greater_equal<int>>(v.rbegin()+1, v.rend()-1).reverse();
        SparseTable<ll, greater<ll>> stpre(pre.begin(), pre.end());
        SparseTable<ll, greater<ll>> stsuf(suf.begin(), suf.end());
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            int l=msl.get()[i-1]+1, r=msr.get()[i-1]+1;
            if(stpre.query(i, r-1)-pre[i-1]>v[i]||stsuf.query(l+1, i)-suf[i+1]>v[i])
            {
                flag = false;
                break;
            }
        }
        cout<<(flag?"YES":"NO")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
