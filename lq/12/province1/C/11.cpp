#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cstring>
const int maxn = 25;
int cnt[maxn];
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
    int t;
    cin>>t;
    while(t--)
    {
        memset(cnt, 0, sizeof(cnt));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            for(int j=0;x;j++)
            {
                if(x % 2) cnt[j]++;
                x /= 2;
            }
        }
        int ans = 0;
        for(int i=20;i>=0;i--)
        {
            int a=cnt[i], b=n-a;
            if(a)
            {
                if(b%2)
                {
                    if(a%2)
                    {
                        if(a==1) ans=1;
                        else ans=-1;
                        break;
                    }
                }
                else if(a%2)
                {
                    ans = 1;
                    break;
                }
            }
        }
        cout<<ans<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
