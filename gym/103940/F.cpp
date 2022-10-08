#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <set>
const int maxn = 105;
typedef long long ll;
ll x[maxn], y[maxn];
bool line(int i,int j,int k)
{
    return (y[k]-y[i])*(x[j]-x[i])==(y[j]-y[i])*(x[k]-x[i]);
}
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    set<pair<int,int>> s;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        s.emplace(x,y);
    }
    n = s.size();
    int cnt = 1;
    for(auto&& [a,b] : s)
    {
        x[cnt] = a;
        y[cnt] = b;
        cnt++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                for(int l=k+1;l<=n;l++)
                    if(!line(i,j,k)&&!line(i,j,l)&&!line(i,k,l)&&!line(j,k,l))
                        ans++;
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
