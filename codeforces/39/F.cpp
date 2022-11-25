#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "lib/local.hpp"
#define debug(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
//==========================================
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
#endif
    auto __c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(m);
    for(int i=0;i<m;i++) cin>>v[i];
    vector<int> w(k);
    for(int i=0;i<k;i++) cin>>w[i];
    int mn = INT_MAX;
    vector<int> r;
    for(int i=0;i<m;i++)
    {
        int cnt = 0;
        for(int j=0;j<k;j++)
            if(w[j]%v[i]==0)
                cnt++;
        if(cnt<mn)
        {
            mn = cnt;
            r = {i+1};
        }
        else if(cnt==mn) r.push_back(i+1);
    }
    cout<<r.size()<<endl;
    for(auto i : r) cout<<i<<' ';
    cout<<endl;
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
