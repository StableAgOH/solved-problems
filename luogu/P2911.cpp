#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 105;
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
    int s1,s2,s3;
    cin>>s1>>s2>>s3;
    for(int i=1;i<=s1;i++)
        for(int j=1;j<=s2;j++)
            for(int k=1;k<=s3;k++)
                a[i+j+k]++;
    int mx = 0xcfcfcfcf, ans;
    for(int i=85;i>=3;i--)
    {
        if(a[i]&&a[i]>=mx)
        {
            mx = a[i];
            ans = i;
        }
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
