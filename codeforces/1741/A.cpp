#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <map>
#include <string>
map<char,int> v = {
    {'S', 1},
    {'M', 2},
    {'L', 3}
};
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        char a=s1.back(), b=s2.back();
        if(a==b)
        {
            int x = count(s1.begin(), s1.end(), 'X');
            int y = count(s2.begin(), s2.end(), 'X');
            if(x==y) cout<<'='<<'\n';
            else if(x<y) cout<<(a=='L'?'<':'>')<<'\n';
            else cout<<(a=='L'?'>':'<')<<'\n';
        }
        else if(v[a]<v[b]) cout<<'<'<<'\n';
        else cout<<'>'<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
