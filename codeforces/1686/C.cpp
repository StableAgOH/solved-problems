#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
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
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        if(v.size()&1) cout<<"NO"<<'\n';
        else
        {
            sort(v.begin(),v.end());
            int mx = 0;
            int cnt = 1;
            for(int i=1;i<v.size();i++)
            {
                if(v[i]==v[i-1]) cnt++;
                else
                {
                    mx = max(mx, cnt);
                    cnt = 1;
                }
            }
            mx = max(mx, cnt);
            int half = v.size()/2;
            if(mx>half) cout<<"NO"<<'\n';
            else if(mx==half&&v[half-1]==v[half]) cout<<"NO"<<'\n';
            else
            {
                cout<<"YES"<<'\n';
                int l=0, m=half;
                for(int l=0;l<half;l++)
                    cout<<v[l]<<' '<<v[l+half]<<' ';
                cout<<'\n';
            }
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
