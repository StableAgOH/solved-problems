#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <set>
#include <algorithm>
#include <iterator>
typedef long long ll;
bool isprime(int x)
{
    if(x==1) return false;
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}
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
        int n,m;
        cin>>n>>m;
        multiset<ll> s1, s2, s3;
        copy_n(istream_iterator<ll>(cin), n, inserter(s1, s1.begin()));
        copy_n(istream_iterator<ll>(cin), m, inserter(s2, s2.begin()));
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
        if(s3.size()!=1||!isprime(*s3.begin())) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
