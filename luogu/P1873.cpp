#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <iterator>
#include <algorithm>
typedef long long ll;
int k;
vector<int> v;
bool check(int m)
{
    ll sum = 0;
    for(auto i : v)
        if(i>m) sum += i-m;
    return sum>=k;
}
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
    int n;
    cin>>n>>k;
    copy_n(istream_iterator<int>(cin), n, inserter(v,v.begin()));
    int l=0, r=1e9;
    while(r-l>5)
    {
        int m = (l+r)>>1;
        if(check(m)) l = m;
        else r = m-1;
    }
    for(int i=r;i>=l;i--)
    {
        if(check(i))
        {
            cout<<i<<endl;
            break;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
