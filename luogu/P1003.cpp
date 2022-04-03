#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <tuple>
typedef tuple<int,int,int,int> tp4;
vector<tp4> v;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,g,k;
        cin>>a>>b>>g>>k;
        v.emplace_back(a,b,g,k);
    }
    int x,y;
    cin>>x>>y;
    int ans = -1;
    for(auto it=v.rbegin(); it!=v.rend(); ++it)
    {
        auto [a,b,g,k] = *it;
        if(x>=a&&x<=a+g&&y>=b&&y<=b+k)
        {
            ans = v.rend()-it;
            break;
        }
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
