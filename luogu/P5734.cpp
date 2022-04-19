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
    int q;
    cin>>q;
    string s;
    cin>>s;
    while(q--)
    {
        int opt,x,y;
        cin>>opt;
        string tmp;
        switch(opt)
        {
        case 1:
            cin>>tmp;
            s.append(tmp);
            cout<<s<<endl;
            break;
        case 2:
            cin>>x>>y;
            s = s.substr(x,y);
            cout<<s<<endl;
            break;
        case 3:
            cin>>x>>tmp;
            s.insert(x,tmp);
            cout<<s<<endl;
            break;
        case 4:
            cin>>tmp;
            auto t = s.find(tmp);
            cout<<(int)((t==string::npos)?-1:t)<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
