#include <iostream>
#include <chrono>
using namespace std;
//==========================================
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
    int n,k;
    cin>>n>>k;
    if(k>=n) cout<<-1<<'\n';
    else if(k==n-1)
    {
        for(int i=1;i<=n;i++) cout<<i<<' ';
        cout<<'\n';
    }
    else
    {
        cout<<n<<' ';
        for(int i=2;i<=k+1;i++) cout<<i<<' ';
        cout<<1<<' ';
        for(int i=k+2;i<n;i++) cout<<i<<' ';
        cout<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
