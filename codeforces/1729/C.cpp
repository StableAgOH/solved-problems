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
        string s;
        cin>>s;
        auto l=s.front(), r=s.back();
        bool flag = false;
        if(l>r)
        {
            flag = true;
            swap(l,r);
        }
        vector<pair<char,int>> v;
        for(int i=1;i<s.length()-1;i++)
            if(s[i]>=l&&s[i]<=r) v.emplace_back(s[i],i+1);
        vector<int> w;
        int sum = 0;
        if(flag)
        {
            w.push_back(1);
            sort(v.begin(), v.end(), greater<>());
            auto last = r;
            for(auto [c,i] : v)
            {
                sum += last-c;
                last = c;
                w.push_back(i);
            }
            w.push_back(s.length());
            sum += last-l;
        }
        else
        {
            w.push_back(1);
            sort(v.begin(), v.end());
            auto last = l;
            for(auto [c,i] : v)
            {
                sum += c-last;
                last = c;
                w.push_back(i);
            }
            w.push_back(s.length());
            sum += r-last;
        }
        cout<<sum<<' '<<w.size()<<endl;
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