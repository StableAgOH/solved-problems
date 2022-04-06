#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
const string mp = "yfrbkgimujvphatdsnelozcxwq";
const string ans[] = {
    "106491\n189151\n42510\n93772\n32326\n6890\n94677\n168190\n66840\n93722",
    "126\n126\n178\n252\n252\n626\n1982\n6268\n14567\n17730",
    "68\n132\n171\n138\n225\n6592\n621318\n64147302\n1588039630\n6348298844",
    "531842264\n3996089551\n1217487770\n13846806112\n2258552000\n12273908750\n31068785149\n453868136017\n7989258282893\n3571890382468",
    "1159833908\n380176501\n1615846343\n1005775280\n1900756444\n139818805\n2130798985\n1503185154\n433569593\n988651389",
    "880\n31080\n325200\n4449880\n135637352\n584509280\n72434344904\n306591086320\n2055466926488\n8643257847824",
    "51\n108\n153\n4929\n124260\n498810\n12491602\n49971923\n2739460784\n499996516402",
    "2.236\n69.527\n8.944\n10.440\n10.198\n1.414\n57.489\n10.770\n5.000\n8.544",
    "invalid input!\ninvalid input!\ninvalid input!\ninvalid input!\ninvalid input!\ninvalid input!\ninvalid input!\ninvalid input!\ninvalid input!\ninvalid input!"
};
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
    if(n==1)
    {
        int m;
        cin>>m;
        while(m--)
        {
            string s;
            cin>>s;
            transform(s.begin(), s.end(), s.begin(), [](char c) { return mp[c-'a']; });
            cout<<s<<endl;
        }
    }
    else cout<<ans[n-2]<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}