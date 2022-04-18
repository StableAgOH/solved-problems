#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <vector>
vector<string> v;
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
    v.resize(n+1);
    for(int i=0;i<n;i++)
    {
        string s;
        int p;
        cin>>s>>p;
        if(s=="."||s=="!") s += '\n';
        else s += " ";
        v[p] = s;
    }
    for(auto &s : v) cout<<s;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
