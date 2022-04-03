#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <iterator>
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
        int n;
        cin>>n;
        vector<int> v;
        copy_n(istream_iterator<int>(cin), n, inserter(v, v.begin()));
        sort(v.begin(), v.end());
        vector<int> w;
        w.push_back(v.front());
        for(auto it=v.begin()+1; it!=v.end(); ++it)
            w.push_back(*it - *(it-1));
        sort(w.begin(), w.end());
        int sum=0, ans=0;
        for(auto i : w) ans += (sum+=i);
        cout<<ans<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
