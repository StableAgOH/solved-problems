#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
#include <string>
#include <cstring>
const int maxn = 2e5+5;
int pre1[maxn],pre2[maxn],pre3[maxn];
char ch[]="RGBRG";
string s;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k>>s;
        for(int i=1;i<=n;i++)
            pre1[i]=pre1[i-1]+(s[i-1]!=ch[i%3]);
        for(int i=1;i<=n;i++)
            pre2[i]=pre2[i-1]+(s[i-1]!=ch[i%3+1]);
        for(int i=1;i<=n;i++)
            pre3[i]=pre3[i-1]+(s[i-1]!=ch[i%3+2]);
        int ans = 0x3f3f3f3f;
        for(int i=k;i<=n;i++)
            ans = min(ans, pre1[i]-pre1[i-k]);
        for(int i=k;i<=n;i++)
            ans = min(ans, pre2[i]-pre2[i-k]);
        for(int i=k;i<=n;i++)
            ans = min(ans, pre3[i]-pre3[i-k]);
        cout<<ans<<endl;
    }
    //======================================
    exit();
}