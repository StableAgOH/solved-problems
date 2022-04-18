#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
typedef long long ll;
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
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    ll d=0, e=0, r=0, de=0, er=0, der=0;
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        if(i>=m)
        {
            if(s[i-m]=='r') r--;
            else if(s[i-m]=='e')
            {
                er -= r;
                e--;
            }
            else if(s[i-m]=='d')
            {
                der -= er;
                de -= e;
                d--;
            }
        }
        if(s[i]=='r')
        {
            der += de;
            er += e;
            r++;
        }
        else if(s[i]=='e')
        {
            de += d;
            e++;
        }
        else if(s[i]=='d') d++;
        ans = max(ans, der);
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
