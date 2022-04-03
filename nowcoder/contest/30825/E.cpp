#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        for(auto it=s.begin(); it!=s.end(); ++it)
        {
            if(*it!='?') continue;
            for(char c='a';c<='c';c++)
            {
                if(it!=s.begin()&&*(it-1)==c) continue;
                if(it!=s.end()-1&&*(it+1)==c) continue;
                *it=c;
                break;
            }
        }
        cout<<s<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
