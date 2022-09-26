#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
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
        string a, b;
        cin>>a>>b;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int x=a[i]-'a', y=b[n-i-1]-'a';
            if(x>y) swap(x,y);
            mp[x*26+y]++;
        }
        auto check = [&]() {
            int cnt = 0;
            for(auto [k,v] : mp)
            {
                if(v&1)
                {
                    if(k/26==k%26) cnt++;
                    else return false;
                }
            }
            if(cnt>1||(cnt==1&&n%2==0)) return false;
            return true;
        };
        cout<<(check()?"YES":"NO")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
