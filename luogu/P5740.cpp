#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
typedef tuple<string,int,int,int> tp4;
vector<tp4> v;
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        int a,b,c;
        cin>>s>>a>>b>>c;
        v.emplace_back(s,a,b,c);
    }
    stable_sort(v.begin(), v.end(), [](auto& t1, auto& t2) {
        auto [s,a,b,c] = t1;
        auto [t,x,y,z] = t2;
        return a+b+c>x+y+z;
    });
    auto [s,a,b,c] = v.front();
    cout<<s<<' '<<a<<' '<<b<<' '<<c<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
