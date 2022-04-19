#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <map>
map<char,int> m;
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
    int maxv = 0xcfcfcfcf;
    for(int i=0;i<4;i++)
    {
        string s;
        getline(cin,s);
        for(auto c : s) if(isupper(c)) maxv = max(maxv, ++m[c]);
    }
    for(int i=maxv;i>0;i--)
    {
        for(char c='A';c<='Z';c++)
        {
            if(m[c]>=i) cout<<'*';
            else cout<<' ';
            if(c!='Z') cout<<' ';
        }
        cout<<endl;
    }
    for(char c='A';c<='Z';c++)
    {
        cout<<c;
        if(c!='Z') cout<<' ';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
