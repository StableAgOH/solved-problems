#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <cmath>
#ifndef CPLIB_ALGORITHM_LIB_DS_SPARSETABLE_HPP
#define CPLIB_ALGORITHM_LIB_DS_SPARSETABLE_HPP

#include <array>
#include <cmath>
#include <functional>
#include <stdexcept>

namespace agoh
{
template<typename T = int32_t, typename C = std::less<T>>
class SparseTable
{
private:
    typedef std::array<T, 25> arr;
    std::vector<arr> f;
    C comp;
    T& m(T& a, T& b)
    {
        return comp(a, b) ? a : b;
    }

public:
    template<typename II>
    requires std::input_iterator<II>
    SparseTable(const II first, const II last)
    {
        for(auto it = first; it != last; ++it)
            f.emplace_back(arr{*it});
        for(int i = 1; (1 << i) <= f.size(); i++)
            for(int j = 0; j + (1 << i) - 1 < f.size(); j++)
                f[j][i] = m(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
    }
    /**
     * @param l Left endpoint of the closed range, indexed from 0
     * @param r Right endpoint of the closed range, indexed from 0
     * @return RMQ of [l,r]
     */
    T& query(const size_t l, const size_t r)
    {
        if(l > r) throw std::range_error("The left endpoint of the range cannot be greater than the right endpoint");
        auto k = static_cast<size_t>(log2(static_cast<double_t>(r - l + 1)));
        return m(f[l][k], f[r - (1 << k) + 1][k]);
    }
};
} // namespace agoh

#endif // CPLIB_ALGORITHM_LIB_DS_SPARSETABLE_HPP

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
    ll n,m;
    cin>>n>>m;
    vector<ll> v(m+1);
    for(int i=1;i<=m;i++) cin>>v[i];
    agoh::SparseTable<ll,greater<ll>> st(v.begin(), v.end());
    int q;
    cin>>q;
    while(q--)
    {
        ll x,y,p,q,k;
        cin>>x>>y>>p>>q>>k;
        if(abs(p-x)%k||abs(q-y)%k) cout<<"NO"<<endl;
        else
        {
            if(y>q) swap(y,q);
            ll a = x+(n-x)/k*k;
            ll b = p+(n-p)/k*k;
            if(st.query(y,q)>=max(a,b)) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}