#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
const int maxn = 1e5 + 5;
int mp[200];
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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(char c : s) mp[c]++;
    int mn = 0x3f3f3f3f;
    for(int i='A';i<='A'+k-1;i++) mn = min(mn, mp[i]);
    cout<<mn*k<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}