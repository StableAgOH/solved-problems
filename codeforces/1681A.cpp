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
        vector<int> v1;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v1.push_back(x);
        }
        int mx1 = *max_element(v1.begin(),v1.end());
        int m;
        cin>>m;
        vector<int> v2;
        for(int i=0;i<m;i++)
        {
            int x;
            cin>>x;
            v2.push_back(x);
        }
        int mx2 = *max_element(v2.begin(),v2.end());
        if(mx1>mx2) cout<<"Alice\nAlice\n";
        else if(mx1<mx2) cout<<"Bob\nBob\n";
        else cout<<"Alice\nBob\n";
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
