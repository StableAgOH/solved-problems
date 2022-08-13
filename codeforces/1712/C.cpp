#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <unordered_map>
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
        vector<int> v(n+1), pre(n+1);
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
            pre[i] = pre[i-1];
            if(!mp[v[i]]) pre[i]++;
            mp[v[i]] = i;
        }
        int ans = 0;
        for(int i=n-1;i>=1;i--)
        {
            if(v[i]>v[i+1])
            {
                for(int j=i;j>=1;j--) ans = max(ans, pre[mp[v[j]]]);
                break;
            }
        }
        cout<<ans<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}