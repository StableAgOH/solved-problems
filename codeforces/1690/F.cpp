#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <vector>
#include <set>
#include <algorithm>
std::vector<size_t> prefix_function(const std::string& s)
{
    std::vector<size_t> nxt(s.length());
    for(size_t i = 1, j = 0; i < s.length(); i++)
    {
        while(j > 0 && s[j] != s[i])
            j = nxt[j - 1];
        if(s[j] == s[i]) nxt[i] = ++j;
    }
    return nxt;
}
const int maxn = 1e5+5;
typedef long long ll;
ll lcm(ll a, ll b) { return a*b/__gcd(a,b); }
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
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
        string s;
        cin>>s;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<bool> vis(n);
        set<int> st;
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            int f = i;
            int c = i;
            int cnt = 0;
            string sc;
            bool flag = false;
            int _ =0;
            do
            {
                cnt++;
                sc.push_back(s[c]);
                vis[c] = true;
                c = v[c]-1;
            } while(c!=f);
            auto vvv = prefix_function(sc);
            auto _t = sc.length()-vvv[sc.length()-1];
            if(sc.length()%_t==0) st.insert(_t);
            else if(cnt>1) st.insert(cnt);
        }
        ll ans = 1;
        for(auto i : st) ans = lcm(ans, i);
        cout<<ans<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
