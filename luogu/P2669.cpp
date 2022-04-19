#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
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
    int k;
    cin>>k;
    int cnt1=1, cnt2=1, cnt3=1, sum=0;
    for(int i=1;i<=k;i++)
    {
        sum += cnt1;
        if(!--cnt2) cnt1=cnt2=++cnt3;
    }
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
