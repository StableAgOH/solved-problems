#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
int a,b,c;
int trans(char ch)
{
    switch(ch)
    {
    case 'a': return a;
    case 'b': return b;
    case 'c': return c;
    default: return ch-'0';
    }
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
    string s;
    cin>>s;
    for(int i=0;i<s.size();i+=5)
    {
        char c1=s[i],c2=s[i+3];
        switch(c1)
        {
        case 'a': a=trans(c2); break;
        case 'b': b=trans(c2); break;
        case 'c': c=trans(c2); break;
        }
    }
    cout<<a<<' '<<b<<' '<<c<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
