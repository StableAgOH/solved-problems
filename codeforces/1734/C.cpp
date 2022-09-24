#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
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
        int n;
        cin>>n;
        string s;
        cin>>s;
        ll ans = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;i*j<=n;j++)
            {
                if(s[i*j-1]=='1') break;
                if(s[i*j-1]=='0')
                {
                    s[i*j-1] = '2';
                    ans += i;
                }
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
