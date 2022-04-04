#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cmath>
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
    int t;
    cin>>t;
    while(t--)
    {
        long long p,q;
        cin>>p>>q;
        int vec = __gcd(p,q);
        p /= vec;
        q /= vec;
        double tmp1 = sqrt(p+2*q);
        if(p-2*q<0) cout<<"0 0"<<endl;
        else
        {
            double tmp2 = sqrt(p-2*q);
            if((tmp1+tmp2)!=(int)(tmp1+tmp2) || (tmp1-tmp2)!=(int)(tmp1-tmp2))
                cout<<"0 0"<<endl;
            else
            {
                long long a = (tmp1+tmp2)/2;
                long long b = (tmp1-tmp2)/2;
                if (!a || !b)
                {
                    cout<<"0 0"<<endl;
                }
                if(a>b) swap(a,b);
                cout<<a<<' '<<b<<endl;
            }
        }
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
