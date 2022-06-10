#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <set>
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n+1);
        vector<int> ans;
        set<int> s;
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
            s.insert(i);
        }
        if(n==1) cout<<-1<<endl;
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(v[i]!=*s.begin())
                {
                    ans.push_back(*s.begin());
                    s.erase(s.begin());
                }
                else
                {
                    if(i==n)
                    {
                        ans.insert(ans.end()-1, *s.begin());
                    }
                    else
                    {
                        auto it = ++s.begin();
                        ans.push_back(*it);
                        s.erase(it);
                    }
                }
            }
            for(auto i : ans) cout<<i<<" ";
            cout<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
