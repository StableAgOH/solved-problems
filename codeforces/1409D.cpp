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
#include <string>
#include <cmath>
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
        long long n;
        int k;
        cin>>n>>k;
        string s = to_string(n);
        int sum = 0;
        for(auto c : s) sum+=c-'0';
        if(sum<=k)
        {
            cout<<0<<endl;
            continue;
        } 
        sum = 0;
        unsigned long long mul1 = pow(10, s.size());
        unsigned long long mul2 = 0;
        for(size_t i=0;i<s.size();i++)
        {
            int tmp = s[i]-'0';
            if(sum+1+tmp>k)
            {
                cout<<(mul2+1)*mul1-n<<endl;
                break;
            }
            sum+=tmp;
            mul1 /= 10;
            mul2*=10; mul2+=tmp;
        }
    }
    //======================================
    exit();
}