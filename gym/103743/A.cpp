#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <vector>
#include <unordered_map>
unordered_map<string, vector<string>> mp;
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
    bool flag = false;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string s1, s2;
        cin>>s1>>s2;
        auto it = find(mp[s1].begin(), mp[s1].end(), s2);
        if(it!=mp[s1].end()) mp[s1].erase(mp[s1].begin(), it+1);
        mp[s1].emplace_back(s2);
        if(mp[s1].size()==5)
        {
            flag = true;
            break;
        }
    }
    cout<<(flag?"PENTA KILL!":"SAD:(")<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
