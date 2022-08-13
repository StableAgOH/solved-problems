#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
bool check(int m, int k, vector<int> v)
{
    int cnt = 0;
    for(auto& i : v)
    {
        if((i<<1)<m)
        {
            cnt++;
            i = 1e9;
        }
    }
    int tmp = 2;
    for(int i=0;i<v.size()-1;i++) tmp = min(tmp, (v[i]<m)+(v[i+1]<m));
    return cnt+tmp<=k;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int l=0, r=1e9;
        while(l<r)
        {
            int m = ((l+r)>>1)+1;
            if(check(m, k, v)) l = m;
            else r = m-1;
        }
        cout<<l<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
