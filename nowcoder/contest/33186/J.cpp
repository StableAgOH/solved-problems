#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <algorithm>
const int maxn = 2e5+5;
int fa[maxn], siz[maxn];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
set<int> pre[maxn], nxt[maxn];
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
    for(int _t=1;_t<=t;_t++)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) pre[i].clear(), nxt[i].clear();
        iota(fa+1, fa+1+n, 1);
        fill(siz+1, siz+1+n, 1);
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            for(int j=0;j<k;j++)
            {
                int x;
                cin>>x;
                nxt[x].insert(i);
                pre[i].insert(x);
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if(pre[i].size()==1)
            {
                queue<pair<int,int>> q;
                q.emplace(i, *pre[i].begin());
                while(!q.empty())
                {
                    auto [u,p] = q.front();
                    q.pop();
                    int fp = find(p);
                    int fu = find(u);
                    if(fp==fu) continue;
                    if(nxt[fp].size()<nxt[fu].size()) swap(fp, fu);
                    fa[fu] = fp;
                    siz[fp] += siz[fu];
                    for(auto i : nxt[fu])
                    {
                        nxt[fp].insert(i);
                        pre[i].erase(fu);
                        pre[i].insert(fp);
                        if(pre[i].size()==1) q.emplace(i, fp);
                    }
                }
            }
        }
        cout<<"Case #"<<_t<<": "<<*max_element(siz+1, siz+1+n)<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
