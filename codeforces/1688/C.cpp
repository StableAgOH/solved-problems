#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <unordered_map>
#include <vector>
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
        unordered_map<char,int> mp;
        for(int i=1;i<=n+n+1;i++)
        {
            string s;
            cin>>s;
            for(auto c : s) mp[c]++;
        }
        for(auto [k,v] : mp) if(v&1) cout<<k<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
