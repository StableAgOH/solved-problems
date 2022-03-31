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
#include <vector>
#include <algorithm>
int lcm(int a,int b) { return a*b/__gcd(a,b); }
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
        vector<long long> v;
        int n;
        cin>>n;
        long long ans=1;
        for(int i=0;i<n;i++)
        {
            long long x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int l=0, r=v.size()-1;
        long long sum = v.front()*v.back();
        int cnt = 0;
        while(l<=r)
        {
            if(v[l]*v[r]==sum) cnt+=l==r?1:2;
            l++, r--;
        }
        int cnt2=0;
        for(long long i=2;i*i<=sum;i++)
            if(sum%i==0) cnt2+=i*i==sum?1:2;
        if(cnt==n&&n==cnt2) cout<<sum<<endl;
        else cout<<-1<<endl;
    }
    //======================================
    exit();
}