#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
typedef long long ll;
int f[] = {1,0,0,0,0,0,1,0,2,1};
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
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
        string s;
        ll k;
        cin>>s>>k;
        ll ans = 0;
        while(s!="0"&&k)
        {
            int cnt = 0;
            for(auto c : s) cnt += f[c-'0'];
            s = to_string(cnt);
            ans = cnt;
            k--;
        }
        if(k) ans = k%2;
        cout<<ans<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
