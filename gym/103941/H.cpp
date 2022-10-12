#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <string>
#include <functional>
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
        int n,x,y;
        cin>>n>>x>>y;
        x--; y--;
        string s[2];
        cin>>s[0]>>s[1];
        vector<bool> vis(2*n);
        function<bool(int,int,int,int)> test = [&](int p,int q,int f,int g) {
            if(p==2&&q==y) return true;
            if(p<0||p>1||q<0||q>=n) return false;
            int t = p*n+q;
            if(vis[t]) return false;
            vis[t] = true;
            bool ret;
            if(s[p][q]=='I')
            {
                if(f<p) ret = test(p+1,q,p,q);
                else if(f>p) ret = test(p-1,q,p,q);
                else
                {
                    if(g<q) ret = test(p,q+1,p,q);
                    else ret = test(p,q-1,p,q);
                }
            }
            else
            {
                if(f!=p) ret = test(p,q-1,p,q)||test(p,q+1,p,q);
                else ret = test(p-1,q,p,q)||test(p+1,q,p,q);
            }
            vis[t] = false;
            return ret;
        };
        cout<<(test(0,x,-1,x)?"YES":"NO")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
