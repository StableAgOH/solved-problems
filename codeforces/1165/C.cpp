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
#include <list>
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
    list<char> ls(s.begin(), s.end());
    int cnt=1;
    for(auto it=ls.begin();it!=ls.end();++it,cnt++)
    {
        if(cnt%2==0) continue;
        auto it2=it;
        ++it2;
        if(it2==ls.end()) break;
        while(*it==*it2&&it2!=ls.end())
        {
            auto it3 = it2;
            ++it2;
            ls.erase(it3);
        }
    }
    if(ls.size()%2) ls.pop_back();
    cout<<s.length()-ls.size()<<endl;
    for(auto c : ls) cout<<c;
    //======================================
    exit();
}