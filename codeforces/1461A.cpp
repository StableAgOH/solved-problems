#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
string solve(int n,int k)
{
    string ret;
    for(int i=0;i<n;i++)
        ret.push_back((i%3)+'a');
    return ret;
}
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }
    //======================================
#ifdef LOCAL
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}