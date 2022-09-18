#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
const int maxn = 1e6+5;
int pre[maxn], suf[maxn], seg[maxn];
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
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='1') cnt++;
        else cnt = 0;
        seg[i] = seg[i-cnt-1]+(cnt+1)/2;
        pre[i] = cnt;
    }
    cnt = 0;
    for(int i=n;i>=1;i--)
    {
        if(s[i-1]=='1') cnt++;
        else cnt = 0;
        suf[i] = cnt;
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int x = seg[r-pre[r]]-seg[l+suf[l]]+(pre[r]+suf[l]+1)/2;
        int y = (r-l+1)/3;
        if(y<=x) cout<<0<<'\n';
        else cout<<y-x<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
