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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> cntx(n+1), cnty(n+1);
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            cntx[x]++;
            cnty[y]++;
        }
        auto check = [&]() {
            if(!all_of(cntx.begin()+1, cntx.end(), [](int x) { return x<3; })) return false;
            if(!all_of(cnty.begin()+1, cnty.end(), [](int x) { return x<3; })) return false;
            if(count(cntx.begin()+1, cntx.end(), 2)>1) return false;
            if(count(cnty.begin()+1, cnty.end(), 2)>1) return false;
            auto itx = find(cntx.begin(), cntx.end(), 2);
            auto ity = find(cnty.begin(), cnty.end(), 2);
            if(itx!=cntx.end()&&ity!=cnty.end()&&itx-cntx.begin()!=ity-cnty.begin()) return false;
            auto cx = count(cntx.begin()+1, cntx.end(), 0);
            auto cy = count(cnty.begin()+1, cnty.end(), 0);
            if(!cx||!cy) return false;
            return true;
        };
        cout<<(check()?"YES":"NO")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
