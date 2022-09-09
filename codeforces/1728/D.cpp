#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <cstring>
#include <functional>
const int maxn = 2005;
int dp[maxn][maxn];
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
        memset(dp, 0, sizeof(dp));
        string s;
        cin>>s;
        function<int(int,int)> dfs = [&](int l,int r) {
            if(l>r) return 1;
            if(dp[l][r]) return dp[l][r];
            if(s[l]==s[r]) return dp[l][r]=dfs(l+1, r-1);
            if(s[l]==s[l+1]&&s[r]==s[r-1]&&dfs(l+2,r)==1&&dfs(l,r-2)==1) return dp[l][r]=1;
            return dp[l][r]=2;
        };
        cout<<(dfs(0, s.length()-1)==2?"Alice":"Draw")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
