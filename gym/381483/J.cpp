#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
typedef long long ll;
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
        vector<ll> v;
        copy_n(istream_iterator<ll>(cin), n, inserter(v,v.begin()));
        ll sum = accumulate(v.begin(), v.end(), 0LL);
        if(sum&1) cout<<"NO"<<'\n';
        else
        {
            bool flag = false;
            for(auto i :v)
            {
                if(i>sum/2)
                {
                    flag = true;
                    break;
                }
            }
            if(flag) cout<<"NO"<<'\n';
            else cout<<"YES"<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
