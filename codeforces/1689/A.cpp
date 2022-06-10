#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <algorithm>
#include <vector>
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
        int n,m,k;
        cin>>n>>m>>k;
        string a,b,c;
        cin>>a>>b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i=0, j=0;
        int cnt = 0;
        while(i!=a.length()&&j!=b.length())
        {
            if(cnt<k&&(cnt<=-k||a[i]<b[j]))
            {
                c += a[i++];
                cnt = max(cnt, 0)+1;
            }
            else
            {
                c += b[j++];
                cnt = min(cnt, 0)-1;
            }
        }
        cout<<c<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
