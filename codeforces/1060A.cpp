#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 0;
    for(auto c : s)
        if(c=='8')
            cnt++;
    int k = n/11;
    cout<<min(k,cnt)<<endl;
    //======================================
#ifdef LOCAL
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}