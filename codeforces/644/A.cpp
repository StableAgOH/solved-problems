#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
const int maxn = 105;
int arr[maxn][maxn];
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    __red(argc, argv);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,a,b;
    cin>>n>>a>>b;
    if(n>a*b) cout<<-1<<'\n';
    else
    {
        int p = 1;
        if(b&1)
        {
            for(int i=1;i<=a;i++)
                for(int j=1;j<=b;j++)
                    arr[i][j] = p<=n?p++:0;
        }
        else
        {
            for(int i=1;i<=a;i++)
            {
                if(i&1)
                {
                    for(int j=1;j<=b;j++)
                        arr[i][j] = p<=n?p++:0;
                }
                else
                {
                    for(int j=b;j>=1;j--)
                        arr[i][j] = p<=n?p++:0;
                }
            }
        }
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
                cout<<arr[i][j]<<' ';
            cout<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
