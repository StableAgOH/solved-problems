#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#endif
#ifdef LOCAL
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
        int cnt = 0;
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(!(x&1)) cnt++;
            int c = 0;
            while(!(x&1))
            {
                c++;
                x /= 2;
            }
            v.push_back(c);
        }
        if(cnt!=n) cout<<cnt<<endl;
        else
        {
            int tmp = *min_element(v.begin(), v.end());
            cout<<tmp+n-1<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
