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
        vector<double> v;
        for(int i=0;i<n;i++)
        {
            int a,b;
            double p;
            cin>>a>>b>>p;
            double e = a+b*p;
            v.push_back(e);
        }
        sort(v.begin(), v.end());
        vector<double> pre(n);
        pre[0] = v[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1]+v[i];
        double sum = 0;
        for(int i=0;i<n;i++) sum += pre[i];
        cout<<fixed<<setprecision(10)<<sum<<'\n';
    }
    return 0;
}
