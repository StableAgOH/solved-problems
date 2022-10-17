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
        int n,m;
        cin>>n>>m;
        ll odd=0, even=0;
        int oddc=0, evenc=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x&1)
            {
                oddc++;
                odd += x;
            }
            else
            {
                evenc++;
                even += x;
            }
        }
        while(m--)
        {
            int opt,x;
            cin>>opt>>x;
            if(!opt)
            {
                if(x&1)
                {
                    odd += (even+evenc*x);
                    oddc += evenc;
                    even = evenc = 0;
                }
                else
                {
                    even += evenc*x;
                }
            }
            else
            {
                if(x&1)
                {
                    even += (odd+oddc*x);
                    evenc += oddc;
                    odd = oddc = 0;
                }
                else
                {
                    odd += oddc*x;
                }
            }
            cout<<odd+even<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
