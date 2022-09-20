#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
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
        vector<int> v(n+1);
        int lastod=-1, lastev=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
            if(v[i]&1) lastod = i;
            else lastev = i;
        }
        vector<pair<int,int>> w;
        if(v[1]&1)
        {
            for(int i=1;i<lastod;i++)
            {
                if(v[i]&1)
                {
                    v[i] = v[lastod];
                    w.emplace_back(i, lastod);
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(v[i]&1) continue;
                w.emplace_back(1, i);
            }
        }
        else
        {
            for(int i=1;i<lastev;i++)
            {
                if(v[i]&1) continue;
                v[i] = v[lastev];
                w.emplace_back(i, lastev);
            }
            for(int i=1;i<=n;i++)
                if(v[i]&1) w.emplace_back(1, i);
        }
        cout<<w.size()<<endl;
        for(auto [x,y] : w) cout<<x<<' '<<y<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
