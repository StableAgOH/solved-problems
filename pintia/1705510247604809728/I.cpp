#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> b(n); 
        for(int i=0;i<n;i++) cin>>b[i];
        vector<double> p(n);
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            p[i] /= 1e5;
        }
        vector<double> o(n, 1e18);
        for(int i=0;i<n;i++)
        {
            int d = i-b[i]+1;
            if(!p[i]) continue;
            o[i] = d/p[i]-d+1;
        }
        vector<double> e(n+1);
        for(int i=n-1;i>=0;i--) e[i] = min(e[i+1]+1, o[i]);
        cout<<fixed<<setprecision(10)<<e[0]<<'\n';
    }
    return 0;
}
