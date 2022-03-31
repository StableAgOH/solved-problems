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
typedef long long ll;
vector<int> v;
vector<int> tmp;
ll merge(vector<int>& v, int l, int mid, int r)
{
    tmp.clear();
    int p=l, q=mid+1;
    ll sum = 0;
    while(p<=mid&&q<=r)
    {
        if(v[p]<=v[q]) tmp.push_back(v[p++]);
        else
        {
            tmp.push_back(v[q++]);
            sum += mid-p+1;
        }
    }
    while(p<=mid) tmp.push_back(v[p++]);
    while(q<=mid) tmp.push_back(v[q++]);
    copy(tmp.begin(), tmp.end(), v.begin()+l);
    return sum;
}
ll merge_sort(vector<int>& v, int l, int r)   // [l,r]
{
    if(l<r)
    {
        int mid = (l+r)>>1;
        ll sum = 0;
        sum += merge_sort(v, l, mid);
        sum += merge_sort(v, mid+1, r);
        sum += merge(v, l, mid, r);
        return sum;
    }
    else return 0;
}
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<merge_sort(v, 0, n-1)<<endl;
    //======================================
    exit();
}