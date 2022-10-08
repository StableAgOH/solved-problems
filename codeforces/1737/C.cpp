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
        int n;
        cin>>n;
        int r1,c1,r2,c2,r3,c3;
        cin>>r1>>c1>>r2>>c2>>r3>>c3;
        int x,y;
        cin>>x>>y;
        if(abs(r1-r3)==1&&abs(c1-c3)==1)
        {
            swap(r1, r2);
            swap(c1, c2);
        }
        else if(abs(r1-r2)==1&&abs(c1-c2)==1)
        {
            swap(r1, r3);
            swap(c1, c3);
        }
        if((r1==1||r1==n)&&(c1==1||c1==n))
        {
            if(x==r1||y==c1) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
        else
        {
            if(((x&1)!=(r1&1))&&((y&1)!=(c1&1))) cout<<"NO"<<'\n';
            else cout<<"YES"<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
