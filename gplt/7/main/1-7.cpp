#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
bool b1[maxn], b2[maxn];
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n,m,q;
    cin>>n>>m>>q;
    ll ans = ll(n)*m;
    cerr<<ans<<endl;
    int cnt1=0, cnt2=0;
    while(q--)
    {
        int opt,x;
        cin>>opt>>x;
        if(opt)
        {
            if(b2[x]) continue;
            b2[x] = true;
            ans -= n-cnt1;
            cnt2++;
        }
        else 
        {
            if(b1[x]) continue;
            b1[x] = true;
            ans -= m-cnt2;
            cnt1++;
        }
    }
    cout<<ans<<endl;
    return 0;
}