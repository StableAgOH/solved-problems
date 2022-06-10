#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <vector>
#include <cmath>
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
    string s;
    cin>>s;
    vector<int> v;
    int cnt[3] = {0,0,0};
    int sum = 0;
    for(auto c : s)
    {
        if(c=='0') continue;
        int x = (c-'0')%3;
        cnt[x]++;
        sum += x;
    }
    sum %= 3;
    bool flag = false;
    if(sum==0&&cnt[0])
    {
        flag = true;
        cnt[0]--;
    }
    else if(sum==1&&cnt[1])
    {
        flag = true;
        cnt[1]--;
    }
    else if(sum==2&&cnt[2])
    {
        flag = true;
        cnt[2]--;
    }
    if(flag)
    {
        if(cnt[1]==cnt[2]&&cnt[0]) cout<<"kou"<<endl;
        else cout<<"yukari"<<endl;
    }
    else cout<<"yukari"<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
