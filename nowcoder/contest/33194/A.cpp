#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <set>
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
    int n,m;
    cin>>n>>m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    unordered_map<int,int> mp;
    int cnt = 0;
    long long ans = 0;
    for(int l=1,r=0;l<=n;l++)
    {
        while(r<n&&cnt<m)
        {
            r++;
            mp[v[r]]++;
            if(mp[v[r]]==1) cnt++;
        }
        if(cnt==m) ans += n-r+1;
        mp[v[l]]--;
        if(!mp[v[l]]) cnt--;
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
