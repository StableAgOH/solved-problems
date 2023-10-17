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
        vector a(n, vector<ll>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        vector<bool> rflag(n), cflag(n);
        ll sum = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]<0)
                {
                    sum += a[i][j];
                    rflag[i] = cflag[j] = true;
                }
            }
        }
        vector<ll> rmn(n), cmn(n);
        for(int i=0;i<n;i++)
        {
            if(rflag[i]) continue;
            rmn[i] = *min_element(a[i].begin(), a[i].end());;
        }
        for(int j=0;j<n;j++)
        {
            if(cflag[j]) continue;
            ll mn = INT_MAX;
            for(int i=0;i<n;i++) mn = min(mn, a[i][j]);
            cmn[j] = mn;
        }
        ll r = accumulate(rmn.begin(), rmn.end(), 0LL);
        ll c = accumulate(cmn.begin(), cmn.end(), 0LL);
        cout<<min(r,c)+sum<<'\n';
    }
    return 0;
}
