#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/debug.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> c(n*2);
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
            c[i+n] = c[i];
        }
        int p = n-1;
        while(p>=0&&c[p]==c[0]) p--;
        p++;
        int curx=c[p], cnt=0;
        int ans = 0;
        bool flag = false;
        for(int i=p;i<p+n;i++)
        {
            if(c[i]==curx) cnt++;
            else
            {
                if(cnt>=k)
                {
                    ans += (cnt-1)/k+1;
                    flag = true;
                }
                else ans++;
                cnt = 1;
                curx = c[i];
            }
        }
        if(cnt>=k)
        {
            ans += (cnt-1)/k+1;
            flag = true;
        }
        else ans++;
        if(!flag) cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
