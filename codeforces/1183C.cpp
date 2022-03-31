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
        int n,k,a,b;
        cin>>n>>k>>a>>b;
        double p = (double)(n-(long long)k*b)/(a-b);
        if(p>k) cout<<k<<endl;
        else if(p<=0) cout<<-1<<endl;
        else if((int)p==p) cout<<(int)p-1<<endl;
        else cout<<(int)p<<endl;
        // pa + qb < n
        // p + q = k
        // 使得p最大
        // pa + (k-p)b < n
        // pa + kb - pb < n
        // p(a-b) < n-kb
        // p < (n-kb)/(a-b)
    }
    //======================================
    exit();
}