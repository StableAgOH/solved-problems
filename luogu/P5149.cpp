#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <map>
#include <vector>
typedef long long ll;
map<string,int> mp;
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
ll merge_sort(vector<int>& v, int l, int r)
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
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        mp[s] = i;
    }
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        v.push_back(mp[s]);
    }
    cout<<merge_sort(v,0,n-1)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
