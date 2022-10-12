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
    int n;
    cin>>n;
    if(n&1)
    {
        int k = (n+1)/2;
        cout<<k<<endl;
        for(int i=1;i<=k;i++) cout<<i<<' ';
        cout<<endl;
    }
    else
    {
        if(n==2||n==4) cout<<-1<<endl;
        else
        {
            int k = n/2;
            cout<<k<<endl;
            cout<<0<<' ';
            for(int i=2;i<=k;i++) cout<<i<<' ';
            cout<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
