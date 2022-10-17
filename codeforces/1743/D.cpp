#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef LOCAL
#include "debug.hpp"
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<size_t> v0;
    list<size_t> v1;
    bool has1 = false;
    for(size_t i=0;i<s.length();i++)
    {
        if(s[i]=='0'&&has1) v0.push_back(i);
        else if(s[i]=='1')
        {
            v1.push_back(i);
            has1 = true;
        }
    }
    string r = s;
    auto last = -1;
    for(auto i : v0)
    {
        auto p = last==-1?0:i-last;
        queue<list<size_t>::iterator> q;
        for(auto it=v1.begin();it!=v1.end();)
        {
            auto t = *it+p;
            if(*it>i||t>=s.length())
            {
                auto itt = it++;
                v1.erase(itt);
                continue;
            }
            *it = t;
            if(s[t]=='0') q.push(it);
            ++it;
        }
        if(v1.empty()) break;
        if(q.size()!=v1.size())
        {
            while(!q.empty())
            {
                auto f = q.front();
                q.pop();
                v1.erase(f);
            }
            r[i] = '1';
        }
        last = i;
    }
    auto p = r.find('1');
    if(p==string::npos) cout<<0<<'\n';
    else
    {
        for(auto i=p;i<r.length();i++) cout<<r[i];
        cout<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto __c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(__c2-__c1).count()<<"ms"<<endl;
#endif
    return 0;
}
