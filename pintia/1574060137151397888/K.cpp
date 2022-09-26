#include <iostream>
#include <vector>
using namespace std;
const int maxn = 205;
const int mod = 998244353;
const int inv6 = 166374059;
typedef long long ll;
bool s[maxn][maxn], c[maxn][maxn];
#define L [x][y-1]
#define LL [x][y-2]
#define R [x][y+1]
#define RR [x][y+2]
#define U [x-1][y]
#define ULL [x-1][y-2]
#define URR [x-1][y+2]
#define UU [x-2][y]
#define UUL [x-2][y-1]
#define UUR [x-2][y+1]
#define D [x+1][y]
#define DLL [x+1][y-2]
#define DRR [x+1][y+2]
#define DD [x+2][y]
#define DDL [x+2][y-1]
#define DDR [x+2][y+1]
#define UL [x-1][y-1]
#define UR [x-1][y+1]
#define DL [x+1][y-1]
#define DR [x+1][y+1]
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n;
    cin>>n;
    vector<pair<int,int>> sqr, cir;
    ll a=0, b=0;
    for(int i=0;i<n;i++)
    {
        int opt,x,y;
        cin>>opt>>x>>y;
        x += 102;
        y += 102;
        if(opt==1)
        {
            if(s[x][y]) continue;
            s[x][y] = true;
            sqr.emplace_back(x,y);
        }
        else
        {
            if(c[x][y]) continue;
            c[x][y] = true;
            cir.emplace_back(x,y);
        }
    }
    for(auto [x,y] : sqr)
    {
        int t = 16;
        if(s U||s UL||s UU||s UUL||c U||c UL) t -= 2;
        else if(s L) t--;
        if(s U||s UR||s UU||s UUR||c U||c UR) t -= 2;
        else if(s R) t--;
        if(s R||s UR||s RR||s URR||c R||c UR) t -= 2;
        else if(s U) t--;
        if(s R||s DR||s RR||s DRR||c R||c DR) t -= 2;
        else if(s D) t--;
        if(s D||s DR||s DD||s DDR||c D||c DR) t -= 2;
        else if(s R) t--;
        if(s D||s DL||s DD||s DDL||c D||c DL) t -= 2;
        else if(s L) t--;
        if(s L||s DL||s LL||s DLL||c L||c DL) t -= 2;
        else if(s D) t--;
        if(s L||s UL||s LL||s ULL||c L||c UL) t -= 2;
        else if(s U) t--;
        a += t;
    }
    for(auto [x,y] : cir)
    {
        if(s[x][y]) continue;
        int t = 12;
        if(c UL||s UL||s L||s U||(c U&&c L)) t -= 3;
        else if((c L&&!c U)||(!c L&&c U)) t -= 2;
        if(c UR||s UR||s R||s U||(c U&&c R)) t -= 3;
        else if((c R&&!c U)||(!c R&&c U)) t -= 2;
        if(c DR||s DR||s R||s D||(c D&&c R)) t -= 3;
        else if((c R&&!c D)||(!c R&&c D)) t -= 2;
        if(c DL||s DL||s L||s D||(c D&&c L)) t -= 3;
        else if((c L&&!c D)||(!c L&&c D)) t -= 2;
        b += t;
    }
    cout<<a/2<<' '<<b*inv6%mod<<endl;
    return 0;
}
