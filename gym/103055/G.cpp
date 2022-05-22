#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <numeric>
#include <unordered_map>
#include <queue>
const int maxn = 5e5+5;
typedef long long ll;
unordered_map<ll,ll> fa, val;
ll hs(ll a,ll b) { return (a<<32)+b; }
ll find(ll x)
{
    if(fa[x]==x) return x;
    ll rt = find(fa[x]);
    val[x] += val[fa[x]];
    return fa[x] = rt;
}
void merge(ll x,ll y)
{
    ll fx=find(x), fy=find(y);
    if(fx==fy) return;
    val[fy] += val[fx];
    fa[fx] = fy;
}
const int d[6][2] = {
    {-1,1}, {-1,0}, {0,1}, {0,-1}, {1,0}, {1,-1}
};
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int q;
    cin>>q;
    while(q--)
    {
        int opt,x,y;
        cin>>opt>>x>>y;
        ll t = hs(x,y);
        if(opt==1)
        {
            fa[t] = t;
            int v = 6;
            queue<ll> que;
            for(int i=0;i<6;i++)
            {
                int p = x+d[i][0];
                int q = y+d[i][1];
                ll tt = hs(p,q);
                if(fa.find(tt)!=fa.end())
                {
                    v -= 2;
                    que.emplace(tt);
                }
            }
            val[t] = v;
            while(!que.empty())
            {
                ll f = que.front();
                que.pop();
                merge(t, f);
            }
        }
        else
        {
            ll ft = find(t);
            cout<<val[ft]<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
