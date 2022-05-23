#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <unordered_map>
#include <cmath>
#include <numeric>
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
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            mp[x]++;
        }
        cout<<int(ceil(accumulate(mp.begin(), mp.end(), 0, [](int x,pii&& p) { return x+min(2,p.second); })/2.0))<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
