#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <map>
#include <queue>
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
        map<char,int> mp;
        for(char c='0';c<='9';c++) mp[c] = -1;
        for(size_t i=0;i<s.length();i++) mp[s[i]] = i;
        string a;
        priority_queue<char,vector<char>,greater<char>> pq;
        int p = 0;
        for(char c='0';c<='9';c++)
        {
            while(!pq.empty()&&pq.top()==c)
            {
                a.push_back(c);
                pq.pop();
            }
            while(p<=mp[c])
            {
                if(s[p]==c) a.push_back(c);
                else pq.push(min('9', char(s[p]+1)));
                p++;
            }
        }
        cout<<a<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
