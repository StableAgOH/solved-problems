#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <unordered_set>
const int maxn = 1e5+5;
typedef long long ll;
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
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int mx = -1e9+3, x = 1e9+7;
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            if(b[i])
            {
                int t = a[i]-b[i];
                if(t>=0&&x==1e9+7) x = t;
                else if(x!=t)
                {
                    flag = false;
                    break;
                }
            }
            if(!b[i])
            {
                mx = max(mx, a[i]);
            }
        }
        cout<<(flag&&mx<=x?"YES":"NO")<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
