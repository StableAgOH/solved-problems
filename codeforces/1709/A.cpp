#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
const int maxn = 1e5+5;
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
        int x;
        cin>>x;
        int a[4];
        int cnt = 0;
        for(int i=1;i<=3;i++) cin>>a[i];
        int cur = x;
        while(cur)
        {
            cur = a[cur];
            cnt++;
        }
        if(cnt!=3) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}