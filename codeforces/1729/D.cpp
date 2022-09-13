#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <set>
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
        vector<int> x(n), y(n);
        for(int i=0;i<n;i++) cin>>x[i];
        for(int i=0;i<n;i++) cin>>y[i];
        int cnt = 0;
        multiset<int> s;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int t = y[i]-x[i];
            if(t<0) s.insert(t);
            else v.push_back(t);
        }
        sort(v.begin(), v.end());
        for(int i=v.size()-1;i>=0;i--)
        {
            auto it = s.lower_bound(-v[i]);
            if(it!=s.end())
            {
                s.erase(it);
                cnt++;
            }
            else
            {
                cnt += (i+1)/2;
                break;
            }
        }
        cout<<cnt<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}