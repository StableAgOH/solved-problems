#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cstring>
#include <algorithm>
const int maxn = 5e5+5;
int n,m,h;
class BIT
{
private:
    int d[maxn];
    int lowbit(int x) { return x&(-x); }
    int hs(int x,int y,int z) { return (x-1)*m*h+(y-1)*h+z; }
public:
    void init() { memset(d, 0xcf, sizeof(d)); }
    void update(int x,int y,int z,int v)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            for(int j=y;j<=m;j+=lowbit(j))
                for(int k=z;k<=h;k+=lowbit(k))
                    d[hs(i,j,k)] = max(d[hs(i,j,k)], v);
    }
    int query(int x,int y,int z)
    {
        int ret = 0xcfcfcfcf;
        for(int i=x;i>0;i-=lowbit(i))
            for(int j=y;j>0;j-=lowbit(j))
                for(int k=z;k>0;k-=lowbit(k))
                    ret = max(ret, d[hs(i,j,k)]);
        return ret;
    }
};
BIT bits[8];
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<8;i++) bits[i].init();
        int q;
        cin>>n>>m>>h>>q;
        while(q--)
        {
            int opt,x,y,z;
            cin>>opt>>x>>y>>z;
            if(opt==1)
            {
                bits[0].update(x    ,y    ,z    , x+y+z);
                bits[1].update(x    ,y    ,h-z+1, x+y-z);
                bits[2].update(x    ,m-y+1,z    , x-y+z);
                bits[3].update(x    ,m-y+1,h-z+1, x-y-z);
                bits[4].update(n-x+1,y    ,z    ,-x+y+z);
                bits[5].update(n-x+1,y    ,h-z+1,-x+y-z);
                bits[6].update(n-x+1,m-y+1,z    ,-x-y+z);
                bits[7].update(n-x+1,m-y+1,h-z+1,-x-y-z);
            }
            else 
            {
                cout<<min({
                     x+y+z-bits[0].query(x    ,y    ,z    ),
                     x+y-z-bits[1].query(x    ,y    ,h-z+1),
                     x-y+z-bits[2].query(x    ,m-y+1,z    ),
                     x-y-z-bits[3].query(x    ,m-y+1,h-z+1),
                    -x+y+z-bits[4].query(n-x+1,y    ,z    ),
                    -x+y-z-bits[5].query(n-x+1,y    ,h-z+1),
                    -x-y+z-bits[6].query(n-x+1,m-y+1,z    ),
                    -x-y-z-bits[7].query(n-x+1,m-y+1,h-z+1),
                })<<endl;
            }
        }
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
