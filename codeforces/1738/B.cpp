#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
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
        int n,k;
        cin>>n>>k;
        vector<ll> v(k+1), w(k+1);
        for(int i=1;i<=k;i++) cin>>v[i];
        if(k==1) cout<<"Yes"<<'\n';
        else
        {
            for(int i=1;i<=k;i++) w[i] = v[i]-v[i-1];
            if(n==k) cout<<(is_sorted(w.begin()+1, w.end())?"Yes":"No")<<'\n';
            else
            {
                if(w[1]<=w[2]*(n-k+1)&&is_sorted(w.begin()+2, w.end())) cout<<"Yes"<<'\n';
                else cout<<"No"<<'\n';
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
