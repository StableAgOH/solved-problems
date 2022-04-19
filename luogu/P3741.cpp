#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
void change(char &c)
{
    if(c=='V') c='K';
    else c='V';
}
string s, sub="VK";
int ct()
{
    int x=0,idx=0;
    while((idx=s.find(sub,idx))!=string::npos)
		x++,idx++;
    return x;
}
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
    cin>>n>>s;
    int ans = ct();
    for(auto &c : s)
    {
        change(c);
        int t = ct();
        ans = max(ans,t);
        change(c);
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
