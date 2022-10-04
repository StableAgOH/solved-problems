#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <vector>
#include <numeric>
#include <functional>
#include <unordered_map>
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
        string s;
        cin>>s;
        unordered_map<char,char> frt, nxt;
        vector<int> fa(150);
        iota(fa.begin(), fa.end(), 0);
        function<int(int)> find = [&](int x) { return fa[x]==x?x:fa[x]=find(fa[x]); };
        int cnt = 26;
        for(auto c : s)
        {
            if(frt[c]) cout<<frt[c];
            else
            {
                for(char p='a';p<='z';p++)
                {
                    if(nxt[p]) continue;
                    if(cnt>1&&find(p)==find(c)) continue;
                    fa[find(p)] = find(c);
                    nxt[p] = c;
                    frt[c] = p;
                    cout<<p;
                    cnt--;
                    break;
                }
            }
        }
        cout<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
