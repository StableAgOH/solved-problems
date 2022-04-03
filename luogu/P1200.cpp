#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
#include <algorithm>
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
    string s1, s2;
    cin>>s1>>s2;
    unsigned int mul1=1, mul2=1;
    for_each(s1.begin(), s1.end(), [&mul1](auto c) { mul1 *= c-'A'+1; });
    for_each(s2.begin(), s2.end(), [&mul2](auto c) { mul2 *= c-'A'+1; });
    cout<<(mul1%47==mul2%47?"GO":"STAY")<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
