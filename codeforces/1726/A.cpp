#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int mx = v.back()-v.front();
        for(int i=0;i<n-1;i++) mx = max(mx, v[i]-v[i+1]);
        mx = max(mx, *max_element(v.begin(), v.end())-v.front());
        mx = max(mx, v.back()-*min_element(v.begin(), v.end()));
        cout<<mx<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
