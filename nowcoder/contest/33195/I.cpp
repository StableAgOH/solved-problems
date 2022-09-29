#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <cstring>
const int maxs = 2e7+5;
typedef pair<int,int> pii;
bool exist[maxs];
vector<pii> a, b;
pii c[maxs];
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
    int n,m;
    cin>>n>>m;
    int p=0, q=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(c[x].first)
        {
            if(!p)
            {
                p = c[x].first;
                q = i;
            }
            continue;
        }
        c[x].first = i;
        a.emplace_back(x, i);
    }
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        if(c[x].second)
        {
            if(p)
            {
                cout<<p<<' '<<q<<' '<<c[x].second<<' '<<i<<endl;
                goto end;
            }
            continue;
        }
        c[x].second = i;
        b.emplace_back(x, i);
    }
    for(int i=0;i<=2e7;i++) c[i].first = c[i].second = 0;
    for(size_t i=0;i<a.size();i++)
    {
        for(size_t j=0;j<b.size();j++)
        {
            int x = a[i].first+b[j].first;
            if(exist[x])
            {
                cout<<a[i].second<<' '<<c[x].first<<' '<<b[j].second<<' '<<c[x].second<<endl;
                goto end;
            }
            exist[x] = true;
            c[x] = {a[i].second, b[j].second};
        }
    }
    cout<<-1<<endl;
end:
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
