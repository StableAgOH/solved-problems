#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <algorithm>
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
    string a,b;
    getline(cin, a);
    getline(cin, b);
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    a = ' '+a+' ';
    b = ' '+b+' ';
    if(b.find(a)==string::npos) cout<<-1<<endl;
    else
    {
        int alpha = b.find(a);
        int beta = b.find(a);
        int s = 0;
        while(beta!=string::npos)
        {
            s++;
            beta = b.find(a,beta+1);
        }
        cout<<s<<' '<<alpha<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
