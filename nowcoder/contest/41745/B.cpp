#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 5005;
int a[maxn];
bool b[maxn];
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
    for(int i=1;i<=n;i++) cin>>a[i];
    int cur = 1;
    for(int i=n;i>=1;i--)
    {
        if(b[i]) continue;
        for(int j=cur;j<=n;j++)
        {
            b[a[j]] = true;
            if(a[j]==i)
            {
                for(int k=j;k>=cur;k--) cout<<a[k]<<' ';
                cur = j+1;
                break;
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
