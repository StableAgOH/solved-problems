#include <iostream>
#include <chrono>
using namespace std;
//==========================================
bool b[10];
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    for(int i=1;i<=6;i++)
    {
        string s;
        cin>>s;
        if(s=="true") b[i] = true;
    }
    int ans = 4;
    if(b[3]==b[6]) ans++;
    if(b[2]==b[5]) ans++;
    if(b[1]==b[4]) ans++;
    if(b[1]==b[4]&&b[2]==b[5]&&b[3]==b[6]&&!(b[1]&&b[4]&&b[3]&&b[6]&&!b[2]&&!b[5])&&!(!b[1]&&!b[4]&&!b[3]&&!b[6]&&b[2]&&b[5])) ans++;
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
