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
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l,r,cnt=0;
        if(n%2) l=r=n/2;
        else l=n/2-1, r=n/2;
        char c = s[l];
        while(l>=0&&r<=n&&s[l]==c&&s[r]==c)
        {
            cnt += (l==r)?1:2;
            l--, r++;
        }
        cout<<cnt<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
