#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
const int maxn = 1e4+5;
int a[maxn];
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
    int l,m;
    cin>>l>>m;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        for(int j=x;j<=y;j++)
            a[j]=1;
    }
    cout<<count(a, a+l+1, 0)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
