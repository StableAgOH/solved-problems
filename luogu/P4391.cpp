#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
const int maxn = 1e6+5;
int nxt[maxn];
string s;
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
    int n;
    cin>>n;
    cin>>s;
    for(int i=1,j=0;i<s.length();i++)
    {
        while(j&&s[i]!=s[j])
            j=nxt[j-1];
        if(s[i]==s[j]) nxt[i]=++j;
    }
    cout<<s.length()-nxt[s.length()-1]<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}