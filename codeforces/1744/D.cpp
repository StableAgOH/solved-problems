#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
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
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            while(x%2==0)
            {
                cnt++;
                x /= 2;
            }
        }
        if(cnt>n) cout<<0<<'\n';
        else
        {
            cnt = n-cnt;
            vector<int> v;
            for(int i=1;i<=n;i++)
            {
                int c = 0;
                int x = i;
                while(x%2==0)
                {
                    c++;
                    x /= 2;
                }
                if(c) v.push_back(c);
            }
            sort(v.begin(), v.end(), greater<>());
            int ans = 0;
            for(auto i : v)
            {
                if(i<=cnt)
                {
                    cnt -= i;
                    ans++;
                }
            }
            if(cnt) cout<<-1<<'\n';
            else cout<<ans<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
