#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
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
        vector<int> v(n+1), w(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        bool flag = false;
        for(int i=1;i<=n;i++)
        {
            if(v[i]&&v[i]<=w[i-1])
            {
                flag = true;
                break;
            }
            w[i] = w[i-1]+v[i];
        }
        if(flag) cout<<-1<<endl;
        else
        {
            for(int i=1;i<=n;i++) cout<<w[i]<<' ';
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
