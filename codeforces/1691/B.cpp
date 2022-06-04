#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
#include <unordered_map>
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
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
        vector<int> v;
        unordered_map<int,vector<int>> mp;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
            mp[x].push_back(i);
        }
        bool flag = true;
        for(auto [k,v] : mp)
        {
            if(v.size()==1)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            for(auto i : v)
            {
                auto &&vt = mp[i];
                if(vt.size()>1)
                {
                    cout<<*(vt.begin()+1)<<' ';
                    vt.erase(vt.begin()+1);
                }
                else cout<<vt.back()<<' ';
            }
            cout<<'\n';
        }
        else cout<<-1<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
