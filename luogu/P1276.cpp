#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
const int maxn = 1e4+5;
int a[maxn], v[maxn];
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
    int n,m;
    int c=0,d=0;
    cin>>n>>m;
    fill(a, a+n+1, 1);
    while(m--)
    {
        int opt,x,y;
        cin>>opt>>x>>y;
        if(!opt)
        {
            for(int i=x;i<=y;i++)
            {
                if(!a[i]) continue;
                a[i]--;
                if(v[i]==1) d++;
            }
        }
        else
        {
            for(int i=x;i<=y;i++)
            {
                if(a[i]) continue;
                a[i]++;
                v[i]=1;
            }
                
        }
    }
    for(int i=0;i<=n;i++)
        if(v[i]==1&&a[i])
            c++;
    cout<<c<<endl;
    cout<<d<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
