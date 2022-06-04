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
#include <string>
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
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<x;i++)
    {
        if(i==y)
        {
            if(s[s.length()-i-1]=='0') cnt++;
        }
        else if(s[s.length()-i-1]=='1') cnt++;
    }
    cout<<cnt<<endl;
    //======================================
    exit();
}