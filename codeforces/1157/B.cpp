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
int a[15];
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=1;i<=9;i++) cin>>a[i];
    bool flag=false;
    for(auto &c : s)
    {
        if(flag)
        {
            if(a[c-'0']>=c-'0')
                c=a[c-'0']+'0';
            else break;
        }
        else if(!flag&&a[c-'0']>c-'0')
        {
            c=a[c-'0']+'0';
            flag=true;
        }
    }
    cout<<s<<endl;
    //======================================
    exit();
}