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
    int n;
    cin>>n;
    int len = 0;
    int mx1=0, mx2=0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        len += s.length();
        int cnt1 = s.front()=='0';
        int cnt2 = s.front()=='1';
        for(int j=1;j<s.length();j++)
            if(s[j]!=s[j-1]) cnt1++, cnt2++;
        mx1 = max(mx1, cnt1);
        mx2 = max(mx2, cnt2);
    }
    int mn = min(mx1, mx2);
    cout<<len-1-mn<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}