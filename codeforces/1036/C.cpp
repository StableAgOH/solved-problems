#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
typedef long long ll;
vector<int> num;
bool check(int cnt, int i)
{
    if(!i) return cnt;
    return cnt-1;
}
ll dp[20][4];
ll dfs(int pos,bool limit,int cnt)
{
    if(pos==num.size()) return 1;
    if(!cnt) return 1;
    if(!limit && dp[pos][cnt]) return dp[pos][cnt];
    int mx = limit?num[pos]:9;
    ll ret = 0;
    for(int i=0;i<=mx;i++)
        ret += dfs(pos+1, limit&&i==mx, (!i)?cnt:cnt-1);
    return dp[pos][cnt] = ret;
}
#include <cstring>
ll calc(ll x)
{
    num.clear();
    memset(dp, 0, sizeof(dp));
    while(x)
    {
        num.push_back(x%10);
        x/=10;
    }
    reverse(num.begin(), num.end());
    return dfs(0, true, 3);
}
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<calc(r)-calc(l-1)<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}