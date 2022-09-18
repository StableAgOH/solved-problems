#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
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
    string s1, s2;
    cin>>s1>>s2;
    for(int i=1;i<=s1.length();i++) dp[i][0] = i;
    for(int j=1;j<=s2.length();j++) dp[0][j] = j;
    for(int i=1;i<=s1.length();i++)
        for(int j=1;j<=s2.length();j++)
                dp[i][j] = min({
                    dp[i-1][j]+1,
                    dp[i][j-1]+1,
                    dp[i-1][j-1]+(s1[i-1]!=s2[j-1])
                });
    cout<<dp[s1.length()][s2.length()]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
