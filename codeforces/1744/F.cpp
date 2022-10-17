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
        vector<int> v(n), p(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            p[v[i]] = i;
        }
        ll l=p[0], r=p[0];
        ll cnt = 1;
        for(ll i=0;i<n-1;i++)
        {
            if(p[i]<l) l = p[i];
            else if(p[i]>r) r = p[i];
            if(p[i+1]>=l&&p[i+1]<=r) continue;
            ll k = (i+1)*2-(r-l+1);
            if(k<-1) continue;
            else
            {
                ll L,R;
                if(p[i+1]<l)
                {
                    L = min(k, l-p[i+1]-1);
                    R = min(k, n-1-r);
                }
                else if(p[i+1]>r)
                {
                    L = min(k, l);
                    R = min(k, p[i+1]-r-1);
                }
                ll T = min(L, k-R);
                cnt += (T+1)*(R+1)+(L-T)*(R+R-(L-T)+1)/2;
            }
        }
        cout<<cnt<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
