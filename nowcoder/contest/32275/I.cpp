#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <string>
#include <bitset>
const int mod = 1e9+7;
typedef long long ll;
int n;
ll dp[11][1550];
vector<int> v;
const int xxx_ = 7;
const int xx_x = xxx_<<3;
const int x_xx = xxx_<<6;
const int _xxx = xxx_<<9;
inline bool conf(int x,int y)
{
    if((x&xxx_)==(y&xxx_)) return true;
    if(n>=2)
    {
        if((x&xx_x)==(y&xx_x)) return true;
        if(n>=3)
        {
            if((x&x_xx)==(y&x_xx)) return true;
            if(n>=4) if((x&_xxx)==(y&_xxx)) return true;
        }
    }
    return false;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int m;
    cin>>n>>m;
    switch(n)
    {
    case 1: for(int a=1;a<=7;a++) { dp[1][v.size()]=1; v.push_back(a); } break;
    case 2: for(int a=1;a<=7;a++) for(int b=1;b<=7;b++) if(a!=b) { int p=(a<<3)+b; dp[1][v.size()]=1; v.push_back(p); } break;
    case 3: for(int a=1;a<=7;a++) for(int b=1;b<=7;b++) if(a!=b) for(int c=1;c<=7;c++) if(b!=c) { int p=(a<<6)+(b<<3)+c; dp[1][v.size()]=1; v.push_back(p); } break;
    case 4: for(int a=1;a<=7;a++) for(int b=1;b<=7;b++) if(a!=b) for(int c=1;c<=7;c++) if(b!=c) for(int d=1;d<=7;d++) if(c!=d) { int p=(a<<9)+(b<<6)+(c<<3)+d; dp[1][v.size()]=1; v.push_back(p); } break;
    }
    for(int i=2;i<=m;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            for(int k=0;k<v.size();k++)
            {
                if(conf(v[j],v[k])) continue;
                dp[i][j] = (dp[i][j]+dp[i-1][k])%mod;
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<v.size();i++)
        ans = (ans+dp[m][i])%mod;
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
