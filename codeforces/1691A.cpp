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
        vector<pii> v;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            x &= 1;
            if(v.empty()) v.emplace_back(x,1);
            else
            {
                if(v.back().first==x) v.back().second++;
                else v.emplace_back(x,1);
            }
        }
        int cnt1=0, cnt2=0;
        for(auto [k,v] : v)
        {
            if(k) cnt1 += v;
            else cnt2 += v;
        }
        cout<<min(cnt1,cnt2)<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
