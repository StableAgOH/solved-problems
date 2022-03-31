#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
#include <cstring>
#include <vector>
const int maxn = 2e5+5;
vector<int> ans;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        ans.clear();
        int n,k;
        cin>>n>>k;
        int odd=0, rem = 0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(x%2)
            {
                odd++;
                if(odd>=k) rem++;
                else ans.push_back(i);
            }
            else continue;
        }
        if(odd+1<k||rem%2==0) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int i : ans) cout<<i<<' ';
            cout<<n<<' '<<endl;
        }
    }
    //======================================
    exit();
}