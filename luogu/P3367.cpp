#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <numeric>
const int maxn = 5e5+5;
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
    int n,m;
    cin>>n>>m;
    iota(fa+1, fa+1+n, 1);
    while(m--)
    {
        int opt,x,y;
        cin>>opt>>x>>y;
        if(opt==1) merge(x,y);
        else cout<<(find(x)==find(y)?'Y':'N')<<'\n';
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}