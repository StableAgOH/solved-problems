#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <tuple>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <ranges>
const int maxn = 5e4+5;
const int maxm = 2e5+5;
typedef tuple<int,int,int> tp3;
vector<tp3> edges;
int fa[maxn];
int find(int x) { return x==fa[x]?x:fa[x]=find(fa[x]); }
inline void merge(int x,int y) { fa[find(x)]=find(y); }
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
    int n,m;
    cin>>n>>m;
    iota(fa+1, fa+1+n, 1);
    istream_iterator<int> isit(cin);
    for(int i=0;i<m;i++) edges.emplace_back(*isit++, *isit++, *isit++);
    sort(edges.begin(), edges.end());
    int sum = 0;
    for(auto [w,u,v] : edges | views::filter([](auto t) { return find(get<1>(t)) != find(get<2>(t)); }))
    {
        merge(u,v);
        n--;
        sum += w;
    }
    if(n==1) cout<<sum<<endl;
    else cout<<"orz"<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
