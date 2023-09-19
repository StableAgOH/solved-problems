#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<string> a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int cnt = 0;
    map<string,int> ma, mb;
    for(int i=0;i<n;i++)
    {
        auto& s = a[i];
        if(ma.find(s)==ma.end()) ma[s] = ++cnt;
    }
    vector<string> rk1(cnt);
    for(auto& [k,v] : ma) rk1[v-1] = k;
    cnt = 0;
    for(int i=0;i<m;i++)
    {
        auto& s = b[i];
        if(mb.find(s)==mb.end()) mb[s] = ++cnt;
    }
    vector<string> rk2(cnt);
    for(auto& [k,v] : mb) rk2[v-1] = k;
    vector<string> ans;
    int k = min(rk1.size(), rk2.size());
    for(int i=0;i<k;i++)
    {
        ans.push_back(rk1[i]);
        ans.push_back(rk2[i]);
    }
    if(rk1.size()<rk2.size()) rk1.swap(rk2);
    for(int i=k;i<(int)rk1.size();i++) ans.push_back(rk1[i]);
    set<string> st;
    for(auto& s : ans)
    {
        if(st.find(s)==st.end())
        {
            st.insert(s);
            cout<<s<<'\n';
        }
    }
    return 0;
}
