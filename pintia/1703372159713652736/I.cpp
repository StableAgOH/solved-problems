#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
int bit[128], pos[128];
ll sum[2][8];
ll dp[2][65][8];
void add(ll& x, ll y) { if(y<0) y += mod; x += y; if(x>=mod) x -= mod; }
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    for(char c='a';c<='z';c++)
    {
        S += c;
        pos[c] = c-'a'+1;
    }
    for(char c='A';c<='Z';c++)
    {
        S += c;
        bit[c] = 1;
        pos[c] = c-'A'+27;
    }
    for(char c='0';c<='9';c++)
    {
        S += c;
        bit[c] = 2;
        pos[c] = c-'0'+53;
    }
    int n;
    cin>>n;
    string s;
    cin>>s;
    s = '$'+s;
    dp[1&1][0][0] = 1;
    sum[1&1][0] = 1;
    for(int i=1;i<=n;i++)
    {
        memset(dp[(i+1)&1], 0, sizeof(dp[(i+1)&1]));
        auto update = [&](char c)
        {
            int p = pos[c];
            for(int u=0;u<8;u++)
            {
                int v = u|(1<<bit[c]);
                add(dp[(i+1)&1][p][v], sum[i&1][u]-dp[i&1][p][u]);
            }
        };
        if(s[i]=='?') for(auto c : S) update(c);
        else if(islower(s[i]))
        {
            update(s[i]);
            update(toupper(s[i]));
        }
        else update(s[i]);
        for(int u=0;u<8;u++)
        {
            sum[(i+1)&1][u] = 0;
            for(auto c : S) add(sum[(i+1)&1][u], dp[(i+1)&1][pos[c]][u]);
        }
    }
    ll ans = 0;
    for(auto c : S) add(ans, dp[(n+1)&1][pos[c]][7]);
    cout<<ans<<'\n';
    return 0;
}
