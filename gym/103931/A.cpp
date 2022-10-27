#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "lib/debug.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//==========================================
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto __c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    string a,b;
    cin>>a>>b;
    const vector<int> p = {0,1,3,4,6,7};
    string res(8,'$');
    res[2] = '+'; res[5] = '=';
    unordered_map<char,int> req, ign;
    unordered_map<int,char> dis;
    for(size_t i=0;i<p.size();i++)
    {
        int k = p[i];
        switch(b[k])
        {
        case 'P': req[a[k]]++; dis[k] = a[k]; break;
        case 'B': ign[a[k]]++; dis[k] = a[k]; break;
        case 'G': res[k] = a[k]; break;
        }
    }
    auto check = [&]() {
        for(char i='0';i<='9';i++)
        {
            int c = 0;
            for(size_t j=0;j<p.size();j++) if(b[p[j]]!='G'&&res[p[j]]==i) c++;
            if(c<req[i]) return false;
            if(c>req[i]&&ign[i]) return false;
        }
        for(size_t i=0;i<p.size();i++) if(res[p[i]]==dis[p[i]]) return false;
        int x = stoi(res.substr(0, 2));
        int y = stoi(res.substr(3, 2));
        int z = stoi(res.substr(6, 2));
        return x+y==z;
    };
    vector<string> ans;
    function<void(int)> dfs = [&](size_t x) {
        if(x==p.size())
        {
            if(check()) ans.emplace_back(res);
            return;
        }
        int k = p[x];
        if(b[k]=='G') dfs(x+1);
        else
        {
            for(char i='0';i<='9';i++)
            {
                res[k] = i;
                dfs(x+1);
            }
        }
    };
    dfs(0);
    cout<<ans.size()<<'\n';
    for(auto&& s : ans) cout<<s<<'\n';
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
