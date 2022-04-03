#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
#include <algorithm>
#include <iterator>
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
    string s;
    cin>>s;
    int n = s.back()=='X'?10:s.back()-'0';
    s.pop_back();
    vector<int> v;
    copy_if(s.begin(), s.end(), inserter(v, v.begin()), [](auto c) { return c!='-'; });
    transform(v.begin(), v.end(), v.begin(), [](int x) { return x-'0'; });
    int sum = 0;
    for(int i=0;i<v.size();i++) sum += v[i]*(i+1);
    sum %= 11;
    cerr<<sum<<endl;
    if(sum==n) cout<<"Right"<<endl;
    else cout<<s<<char(sum==10?'X':sum+'0')<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
