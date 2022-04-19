#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int x;
    cin>>x;
    bool b1 = !(x%2);
    bool b2 = x>4&&(!(x>12));
    if(b1&&b2) cout<<1<<' ';
    else cout<<0<<' ';
    if(b1||b2) cout<<1<<' ';
    else cout<<0<<' ';
    if(b1^b2) cout<<1<<' ';
    else cout<<0<<' ';
    if(!b1&&!b2) cout<<1<<' ';
    else cout<<0<<endl;
    //======================================
    exit();
}
