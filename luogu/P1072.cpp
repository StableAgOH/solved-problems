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
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a0,a1,b0,b1;
        cin>>a0>>a1>>b0>>b1;
        int p=a0/a1, q=b1/b0, cnt=0;
        for(int x=1;x*x<=b1;x++)
        {
            if(b1%x) continue;
            if(x%a1==0&&__gcd(x/a1,p)==1&&__gcd(q,b1/x)==1) ++cnt;
            int y=b1/x;
            if(x==y) continue; 
            if(y%a1==0&&__gcd(y/a1,p)==1&&__gcd(q,b1/y)==1) ++cnt;
        }
        cout<<cnt<<'\n';
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}