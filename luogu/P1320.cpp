#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
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
    cout<<s.length()<<' ';
    int cnt=0, cur=0;
    for(int i=1;i<=s.length();i++)
    {
        for(int j=0;j<s.length();j++)
        {
            if((s[j]-'0')==cur) cnt++;
            else
            {
                cout<<cnt<<' ';
                cnt = 1;
                cur ^= 1;
            }
        }
        cin>>s;
    }
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
