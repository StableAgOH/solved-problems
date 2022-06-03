#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <tuple>
#include <set>
#ifndef __DSU_HPP__
#define __DSU_HPP__
#endif

#include <numeric>
#include <vector>
namespace agoh
{
class DSU
{
private:
    std::vector<size_t> fa;

public:
    DSU(const size_t n)
    {
        this->fa.resize(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
    }
    size_t find(const size_t x)
    {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool merge(const size_t x, const size_t y)
    {
        auto fx = find(x), fy = find(y);
        if(fx != fy)
        {
            fa[fx] = fy;
            return true;
        }
        else return false;
    }
};
} // namespace agoh
using namespace agoh;
typedef pair<int,int> pii;
typedef tuple<int,int,int,int> tp4;
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#endif
#ifdef LOCAL
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
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
        DSU dsu(n);
        vector<pii> l;
        vector<tp4> v;
        for(int i=0;i<n;i++)
        {
            int c,x,y;
            cin>>c>>x>>y;
            l.emplace_back(x,y);
            v.emplace_back(x,0,c,i);
            v.emplace_back(y,1,c,i);
        }
        sort(v.begin(), v.end());
        set<pii> s1, s2;
        for(auto [p,f,c,i] : v)
        {
            if(!f)
            {
                if(c)
                {
                    s1.emplace(l[i].second, i);
                    for(auto it=s2.begin();it!=s2.end();++it)
                        if(dsu.merge(i, it->second)) --n;
                    if(s2.size()>1) s2.erase(s2.begin(), --s2.end());
                }
                else 
                {
                    s2.emplace(l[i].second, i);
                    for(auto it=s1.begin();it!=s1.end();++it)
                        if(dsu.merge(i, it->second)) --n;
                    if(s1.size()>1) s1.erase(s1.begin(), --s1.end());
                }
            }
            else
            {
                if(c) s1.erase({l[i].second, i});
                else s2.erase({l[i].second, i});
            }
        }
        cout<<n<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
