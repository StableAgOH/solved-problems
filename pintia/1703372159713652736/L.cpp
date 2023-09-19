#include <bits/stdc++.h>
using namespace std;
int div_ceil(int x,int y) { return x/y+!!(x%y); }
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    int ans = 2;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ans = max(ans, div_ceil(x,k));
    }
    cout<<ans<<'\n';
    return 0;
}
