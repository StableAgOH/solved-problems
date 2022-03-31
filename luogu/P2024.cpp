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
const int maxn = 5e4+5;
int fa[maxn], val[maxn];
int find(int x)
{
    if(fa[x]==x) return x;
    int rt = find(fa[x]);
    val[x] += val[fa[x]];
    return fa[x] = rt;
}
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
        fa[i]=i;
    int cnt = 0;
    while(m--)
    {
        int opt,x,y;
        cin>>opt>>x>>y;
        if(x>n||y>n) ++cnt;
        else 
        {
            int fx=find(x), fy=find(y);
            if(opt==1)
            {
                if(fx==fy && (val[x]-val[y])%3) ++cnt;
                else if(fx!=fy)
                {
                    fa[fx] = fy;
                    val[fx] = val[y]-val[x];
                }
            }
            else 
            {
                if(fx==fy && (val[x]-val[y]-1)%3) ++cnt;
                else if(fx!=fy)
                {
                    fa[fx]=fy;
                    val[fx] = val[y]+1-val[x];
                }
            }
        }
    }
    cout<<cnt<<endl;
    //======================================
    exit();
}