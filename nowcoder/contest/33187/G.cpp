#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <cmath>
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
        int n;
        cin>>n;
        int siz = ceil(sqrt(n));
        int i;
        for(i=siz;i<n;i+=siz) for(int j=i;j>i-siz;j--) cout<<j<<' ';
        for(int j=n;j>i-siz;j--) cout<<j<<' ';
        cout<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
