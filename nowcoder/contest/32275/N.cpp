#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <bitset>
typedef bitset<31> bs;
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
        int n;
        cin>>n;
        vector<int> v(31);
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            bs b(x);
            for(int j=30;j>=0;j--) v[j] += b[j];
        }
        bs b(0);
        for(int i=30;i>=0;i--)
            if(v[i]>n-v[i]) b[i] = 1;
        cout<<b.to_ulong()<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
