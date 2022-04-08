#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <tuple>
#include <numeric>
const int maxn = 1005;
typedef long long ll;
typedef tuple<ll,ll,ll> tp3;
tp3 a[maxn];
int fa[maxn];
int find(int x) { return x==fa[x]?x:fa[x]=find(fa[x]); }
inline void merge(int x,int y) { fa[find(x)]=find(y); }
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
        int n,h,r;
        cin>>n>>h>>r;
        iota(fa, fa+n+2, 0);
        for(int i=1;i<=n;i++)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            if(z-r<=0) merge(0,i);
            if(z+r>=h) merge(n+1,i);
            for(int j=1;j<i;j++)
            {
                auto [o,p,q] = a[j];
                if((x-o)*(x-o)+(y-p)*(y-p)+(z-q)*(z-q)<=4LL*r*r)
                    merge(i,j);
            }
            a[i]={x,y,z};
        }
        cout<<(find(0)==find(n+1)?"Yes":"No")<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}