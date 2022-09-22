#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
#include <vector>
#include <algorithm>
typedef pair<int,int> pii;
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
    int n;
    cin>>n;
    vector<pii> a;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a.emplace_back(1<<((int)log2(x)), i);
    }
    sort(a.begin(), a.end());
    vector<int> v(1);
    for(auto&& [x,i] : a)
    {
        while(v.size()<x) v.insert(v.end(), v.begin(), v.end());
        *find(v.begin(), v.end(), 0) = i;
    }
    cout<<v.size()<<endl;
    for(auto i : v) cout<<(i?i:1)<<' ';
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
