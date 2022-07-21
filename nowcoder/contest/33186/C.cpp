#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
#include <cmath>
const int maxn = 2e5+5;
typedef long long ll;
typedef pair<ll,ll> pii;
ll minx[maxn], thr[maxn];
pii points[maxn];
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
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    for(int i=1;i<=k;i++) cin>>points[i].first>>points[i].second;
    while(q--)
    {
        int p,x,y;
        cin>>p>>x>>y;
        points[p] = {x,y};
        fill(minx+1, minx+1+m, n+1);
        for(int i=1;i<=k;i++) minx[points[i].second] = min(minx[points[i].second], points[i].first);
        thr[1] = minx[1];
        int minky = 2;
        for(int i=2;i<=m;i++)
        {
            if((i-1)*minx[minky]>(minky-1)*minx[i]) minky = i;
            thr[i] = min(minx[i], ll(ceil(double(i-1)*minx[minky]/(minky-1))));
        }
        minky = m-1;
        for(int i=m-1;i>=1;i--)
        {
            if((i-m)*minx[minky]<(minky-m)*minx[i]) minky = i;
            thr[i] = min(thr[i], ll(ceil(double(i-m)*minx[minky]/(minky-m))));
        }
        ll sum = 0;
        for(int i=1;i<=m;i++) sum += thr[i]-1;
        cout<<sum<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
