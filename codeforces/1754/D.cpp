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
    int n,m;
    cin>>n>>m;
    unordered_map<int,int> c;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        c[x]++;
        while(c[x]>x)
        {
            c[x] = 0;
            c[x+1]++;
            x++;
        }
    }
    bool flag = true;
    for(int i=1;i<m;i++)
    {
        if(c[i])
        {
            flag = false;
            break;
        }
    }
    if(flag) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
