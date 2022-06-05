#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
typedef long long ll;
int n, mn=0x3f3f3f3f;
void dfs(ll x,int cnt)
{
    auto s = to_string(x);
    if(s.length()==n)
    {
        mn = min(mn, cnt);
        return;
    }
    if(cnt+n-s.length()>=mn) return;
    for(auto c : s) if(c>'1') dfs(x*(c-'0'), cnt+1);
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
    ll x;
    cin>>n>>x;
    string s = to_string(x);
    if(count_if(s.begin(), s.end(), [](char c) { return c<='1'; })==s.length()) cout<<-1<<endl;
    else
    {
        dfs(x,0);
        cout<<mn<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
