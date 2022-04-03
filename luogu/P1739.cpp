#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 1e5 + 5;
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    string s;
    cin>>s;
    int cnt=0;
    for(auto c : s)
    {
        if(c=='@') break;
        if(c=='(') cnt++;
        else if(c==')')
        {
            cnt--;
            if(cnt<0)
            {
                cout<<"NO"<<endl;
                goto end;
            }
        }
    }
    if(cnt) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
end:
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}