#include <iostream>
#include <chrono>
using namespace std;
//==========================================
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
        int n,m;
        cin>>n>>m;
        if(m<n) cout<<"No"<<'\n';
        else
        {
            bool a=n%2, b=m%2;
            if(!a&&b) cout<<"No"<<'\n';
            else if(!a&&!b)
            {
                cout<<"Yes"<<'\n';
                int x = m/n;
                int y = m%n;
                for(int i=1;i<=n-y;i++) cout<<x<<' ';
                for(int i=1;i<=y;i++) cout<<x+1<<' ';
                cout<<endl;
            }
            else
            {
                cout<<"Yes"<<'\n';
                int x = pow(m, 1.0/n);
                int y = m-x*(n-1);
                for(int i=1;i<n;i++) cout<<x<<' ';
                cout<<y<<'\n';
            }
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
