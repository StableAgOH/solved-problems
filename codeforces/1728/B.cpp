#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <numeric>
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
        iota(v.begin(), v.end(), 1);
        int mx = 0;
        for(auto i : v)
        {
            if(mx<i) mx += i;
            else mx = 0;
        }
        vector<int> w = v;
        for(int i=n-2;i>=0;i--)
        {
            swap(v[i], v[i+1]);
            int x = 0;
            for(auto i : v)
            {
                if(x<i) x += i;
                else x = 0;
            }
            if(x>mx)
            {
                mx = x;
                w = v;
            }
            swap(v[i], v[i+1]);
        }
        for(auto i : w) cout<<i<<' ';
        cout<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
