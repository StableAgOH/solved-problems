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
const int maxn=1e5+5;
struct Toy
{
    int forward;
    string vocation;
}toy[maxn];
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>toy[i].forward>>toy[i].vocation;
    int cur = 1;
    while(m--)
    {
        int opt, x;
        cin>>opt>>x;
        if(opt)     // 往右数
        {
            if(toy[cur].forward)    // 朝里(逆时针方向)
            {
                cur-=x;
                while(cur<1) cur+=n;
                
            }
            else                    // 朝外(顺时针方向)
            {
                cur+=x;
                if(cur>n) cur %= n;
            }
        }
        else        // 往左数
        {
            if(toy[cur].forward)    // 朝里(顺时针方向)
            {
                cur+=x;
                if(cur>n) cur %= n;
            }
            else                    // 朝外(逆时针方向)
            {
                cur-=x;
                while(cur<1) cur+=n;
            }
        }
    }
    cout<<toy[cur].vocation<<endl;
    //======================================
    exit();
}