#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
typedef pair<int,int> pii;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
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
        vector<pii> v(n);
        for(int i=0;i<n;i++) cin>>v[i].first;
        for(int i=0;i<n;i++) cin>>v[i].second;
        vector<pii> vswap;
        for(int i=0;i<n-1;i++)
        {
            auto it = min_element(v.begin()+i, v.end());
            if(i==it-v.begin()) continue;
            vswap.emplace_back(i+1, it-v.begin()+1);
            swap(v[i], *it);
        }
        if(is_sorted(v.begin(),v.end(),[](pii& x,pii& y) { return x.second<y.second; }))
        {
            cout<<vswap.size()<<'\n';
            for(auto [p,q] : vswap) cout<<p<<' '<<q<<'\n';
        }
        else cout<<-1<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
