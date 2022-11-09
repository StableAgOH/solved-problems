#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    __red(argc, argv);
    auto __c1 = chrono::high_resolution_clock::now();
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
        string s,r;
        cin>>s>>r;
        s = '#'+s;
        r = '#'+r;
        vector<int> f(n+2);
        bool p = false;
        vector<pair<int,int>> ans;
        for(int i=1;i<=n;i++)
        {
            int x = r[i]-'0';
            if(x^p)
            {
                if(i==1)
                {
                    ans.emplace_back(2,n);
                    f[2] ^= 1;
                    f[n+1] ^= 1;
                }
                else
                {
                    ans.emplace_back(1,i-1);
                    f[1] ^= 1;
                    f[i] ^= 1;
                    p ^= 1;
                }
            }
        }
        debug(ans);
        debug(f);
        int pre = 0;
        for(int i=1;i<=n;i++)
        {
            pre ^= f[i];
            int x = s[i]-'0';
            s[i] = (x^pre)+'0';
        }
        if(count(s.begin(), s.end(), '0')==n)
        {
            cout<<"YES"<<'\n';
            cout<<ans.size()<<'\n';
            for(auto [x,y] : ans) cout<<x<<' '<<y<<'\n';
        }
        else if(count(s.begin(), s.end(), '1')==n)
        {
            cout<<"YES"<<'\n';
            cout<<ans.size()+1<<'\n';
            cout<<1<<' '<<n<<'\n';
            for(auto [x,y] : ans) cout<<x<<' '<<y<<'\n';
        }
        else cout<<"NO"<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
