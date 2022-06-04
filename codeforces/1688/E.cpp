#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <string>
#include <algorithm>
typedef pair<int,int> pii;
int n,m;
int query(const string& s)
{
    cout<<"? "<<s<<endl;
    int x;
    cin>>x;
    return x;
}
int query(int i)
{
    string s(m, '0');
    s[i] = '1';
    return query(s);
}
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
    cin>>n>>m;
    vector<pii> v;
    for(int i=0;i<m;i++) v.emplace_back(query(i), i);
    sort(v.begin(), v.end());
    string ws(m, '0');
    int ans = 0;
    for(auto [x,y] : v)
    {
        int c = 0;
        int sum = 0;
        ws[y] = '1';
        auto t = query(ws);
        if(t!=ans+x)
        {
            ws[y] = '0';
            continue;
        }
        ans += x;
    }
    cout<<"! "<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
