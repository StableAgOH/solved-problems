#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <string>
const int maxn = 1e5+5;
typedef long long ll;
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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    string s;
    cin>>s;
    ll tr=0, tb=0, fr=0, fb=0;
    for(int i=0;i<n;i++)
    {
        bool flag = v[i]&1;
        if(flag&&s[i]=='R')
        {
            tr = max(tr, fb+v[i]);
        }
        else if(flag&&s[i]=='B')
        {
            tb = max(tb, fr+v[i]);
        }
        else if(!flag&&s[i]=='R')
        {
            fr = max(fr, tb+v[i]);
        }
        else if(!flag&&s[i]=='B')
        {
            fb = max(fb, tr+v[i]);
        }
    }
    cout<<max(max(max(tr,tb),fr),fb)<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
