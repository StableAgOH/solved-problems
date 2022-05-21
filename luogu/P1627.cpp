#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <unordered_map>
unordered_map<int,int> mp1, mp2;
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
    int n,m;
    cin>>n>>m;
    int pre = 0;
    int ans = 0;
    mp1[0] = 1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x>m) pre++;
        else if(x<m) pre--;
        cerr<<pre<<' ';
        if(i&1)
        {
            ans += mp2[pre];
            mp1[pre]++;
        }
        else 
        {
            ans += mp1[pre];
            mp2[pre]++;
        }
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
