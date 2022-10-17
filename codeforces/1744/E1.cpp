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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        bool flag = false;
        for(ll t=a*b*2;t<=c*d;t+=a*b)
        {
            for(ll i=2;i*i<=t;i++) if(t%i==0)
            {
                ll x=i, y=t/i;
                if(a<x&&x<=c&&b<y&&y<=d)
                {
                    cout<<x<<' '<<y<<'\n';
                    flag = true;
                    goto end;
                }
                if(a<y&&y<=c&&b<x&&x<=d)
                {
                    cout<<y<<' '<<x<<'\n';
                    flag = true;
                    goto end;
                }
            }
        }
        end:
        if(!flag) cout<<-1<<' '<<-1<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
