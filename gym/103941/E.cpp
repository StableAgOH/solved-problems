#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <vector>
#include <unordered_map>
char solve(const string& s, size_t& fst, int len)
{
    unordered_map<char,int> mp;
    for(size_t i=fst;i<s.length();i++)
    {
        mp[s[i]]++;
        if(mp[s[i]]==len)
        {
            fst = i+1;
            return s[i];
        }
    }
    return 0;
}
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
    string s;
    cin>>s;
    size_t t = 0;
    char a = solve(s, t, 5);
    char b = solve(s, t, 7);
    char c = solve(s, t, 5);
    if(a&&b&&c) cout<<string(5,a)<<string(7,b)<<string(5,c)<<endl;
    else cout<<"none"<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
