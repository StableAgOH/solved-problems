#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <iterator>
vector<int> v;
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
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int ans = 0;
    int cnt = -1;
    int last = 0;
    for(auto it=v.begin();it!=v.end();++it)
    {
        if(*it<last)
        {
            cnt++;
            ans = max(ans, cnt);
        }
        else cnt = 0;
        last = *it;
    }
    cnt = -1;
    last = 0;
    for(auto it=v.rbegin();it!=v.rend();++it)
    {
        if(*it<last)
        {
            cnt++;
            ans = max(ans, cnt);
        }
        else cnt = 0;
        last = *it;
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
