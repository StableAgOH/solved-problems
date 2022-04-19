#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
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
    int l,r;
    cin>>l>>r;
    vector<int> v;
    for(int i=l;i<=r;i++)
        if(i%100!=0&&i%4==0||i%400==0)
            v.push_back(i);
    cout<<v.size()<<endl;
    for(auto i : v) cout<<i<<' ';
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
