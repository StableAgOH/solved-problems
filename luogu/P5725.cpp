#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i*n+j>=10) cout<<i*n+j;
            else cout<<0<<i*n+j;
        }
        cout<<endl;
    }
    cout<<endl;
    int cnt = 1;
    for(int i=(n-1)*2;i>=0;i-=2)
    {
        cout<<string(i,' ');
        for(int j=(n-1)*2-i;j>=0;j-=2)
        {
            if(cnt<10) cout<<0<<cnt++;
            else cout<<cnt++;
        }
        cout<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
