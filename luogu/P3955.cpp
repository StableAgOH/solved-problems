#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
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
    int n,q;
    cin>>n>>q;
    vector<int> v;
    copy_n(istream_iterator<int>(cin), n, inserter(v, v.begin()));
    sort(v.begin(), v.end());
    vector<string> vs;
    transform(v.begin(), v.end(), inserter(vs, vs.begin()), [](int x) { return to_string(x); });
    for(int i=0;i<q;i++)
    {
        int l;
        string s;
        cin>>l>>s;
        for(auto& t : vs)
        {
            if(t.length()<s.length()) continue;
            if(equal(s.rbegin(), s.rend(), t.rbegin()))
            {
                cout<<t<<endl;
                goto nxt;
            }
        }
        cout<<-1<<endl;
        nxt:;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
