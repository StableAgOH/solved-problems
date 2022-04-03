#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
bool isprime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}
vector<int> v;
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
    for(int i=2;i<=n;i++)
        if(isprime(i))
            v.push_back(i);
    for(auto i : v)
    {
        for(auto j : v)
        {
            for(auto k : v)
            {
                if(i+j+k==n)
                {
                    cout<<i<<' '<<j<<' '<<k<<endl;
                    goto end;
                }
            }
        }
    }
end:
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
