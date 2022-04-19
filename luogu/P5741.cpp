#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <vector>
#include <tuple>
#include <cmath>
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
    for(auto it=v.begin();it!=v.end();++it)
    {
        for_each(it+1, v.end(), [&it](auto& t) {
            auto [p,a,b,c] = *it;
            auto [q,x,y,z] = t;
            if(abs(a-x)<=5&&abs(b-y)<=5&&abs(c-z)<=5&&abs(a+b+c-x-y-z)<=10)
                cout<<p<<' '<<q<<'\n';
        });
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
