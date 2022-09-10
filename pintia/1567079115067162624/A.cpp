#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        a[0] += b[0];
        int x = a[0];
        sort(a.begin(), a.end(), greater<>());
        int i;
        for(i=0;i<n;i++)
            if(a[i]==x) break;
        cout<<(i+1<=k?"Yes":"No")<<'\n';
    }
    return 0;
}
