#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <cstring>
#include <algorithm>
const int maxn = 2e5+5;
int nxt[maxn][30];
int fst[maxn];
int f[maxn][20];
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
    int m,n;
    cin>>m>>n;
    string s;
    cin>>s;
    fill(nxt[n], nxt[n]+m, n+1);
    for(int i=n;i;i--)
    {
        memcpy(nxt[i-1], nxt[i], sizeof(nxt[i]));
        nxt[i-1][s[i-1]-'a'] = i;
    }
    for(int i=0;i<=n;i++) fst[i] = *max_element(nxt[i], nxt[i]+m);
    for(int i=0;i<=n;i++) f[i][0] = fst[i];
    for(int i=n;~i;i--)
        for(int k=1;k<20;k++)
            f[i][k] = f[f[i][k-1]][k-1];
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        int cnt = 1;
        for(int k=19;~k;k--)
        {
            if(f[l][k]&&f[l][k]<=r)
            {
                cnt += 1<<k;
                l = f[l][k];
            }
        }
        cout<<cnt<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
