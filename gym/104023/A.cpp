#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int n;
    cin>>n;
    set<string> champ;
    for(int i=0;i<5*n;i++)
    {
        string s;
        cin>>s;
        champ.insert(s);
    }
    int m;
    cin>>m;
    vector<vector<string>> player(6);
    map<string,int> mp;
    for(int i=0;i<m;i++)
    {
        string s;
        int p;
        cin>>s>>p;
        mp[s] = p;
        player[p].emplace_back(s);
    }
    int cnt = 0;
    set<string> st;
    for(auto&& s : champ)
    {
        if(st.find(s)!=st.end()) continue;
        st.insert(s);
        int p = mp[s];
        if(!p) continue;
        vector<bool> has(6);
        has[p] = true;
        for(int i=1;i<=5;i++)
        {
            if(has[i]) continue;
            for(auto&& r : player[i])
            {
                if(st.find(r)!=st.end()) continue;
                if(champ.find(r)!=champ.end()) continue;
                st.insert(r);
                has[i] = true;
                break;
            }
        }
        for(int i=1;i<=5;i++)
        {
            if(has[i]) continue;
            for(auto&& r : player[i])
            {
                if(st.find(r)!=st.end()) continue;
                st.insert(r);
                has[i] = true;
                break;
            }
        }
        if(count(has.begin()+1, has.end(), true)==5) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
