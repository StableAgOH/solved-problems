#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <numeric>
#ifndef __MONOTONY_STACK_HPP__
#define __MONOTONY_STACK_HPP__
#endif

#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
namespace agoh
{
template<typename T = int, typename C = std::less_equal<T>>
class MonotonyStack
{
private:
    std::vector<int> res;
    C comp;

public:
    template<typename II>
    requires std::input_iterator<II> MonotonyStack(const II first, const II last, const int default_value = -1)
    {
        std::stack<int> st;
        for(auto it = first; it != last; ++it)
        {
            while(!st.empty() && comp(*it, *(first + st.top())))
                st.pop();
            res.push_back(st.empty() ? default_value : st.top());
            st.push(it - first);
        }
    }
    auto& reverse()
    {
        std::reverse(this->res.begin(), this->res.end());
        for(auto&& ele : this->res)
            ele = res.size() - ele - 1;
        return *this;
    }
    auto& get()
    {
        return this->res;
    }
};
} // namespace agoh

#ifndef __SPARSE_TABLE_HPP__
#define __SPARSE_TABLE_HPP__
#endif

#include <array>
#include <cassert>
#include <cmath>
#include <functional>
namespace agoh
{
template<typename T = int, typename C = std::less<T>>
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
    requires std::input_iterator<II> SparseTable(const II first, const II last)
    {
        for(auto it = first; it != last; ++it)
            f.emplace_back(arr{*it});
        for(int i = 1; (1 << i) <= f.size(); i++)
            for(int j = 0; j + (1 << i) - 1 < f.size(); j++)
                f[j][i] = m(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
    }
    /**
     * @param l Left endpoint of the closed interval, indexed from 0
     * @param r Right endpoint of the close interval, indexed from 0
     * @return The RMQ of [l,r]
     */
    T& query(const size_t l, const size_t r)
    {
        assert(l <= r);
        size_t k = log2(r - l + 1);
        return m(f[l][k], f[r - (1 << k) + 1][k]);
    }
};
} // namespace agoh

using namespace agoh;
typedef long long ll;
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
        vector<ll> v(n+2);
        for(int i=1;i<=n;i++) cin>>v[i];
        vector<ll> pre(n+2), suf(n+2);
        partial_sum(v.begin(), v.end(), pre.begin());
        partial_sum(v.rbegin(), v.rend(), suf.rbegin());
        auto msl = MonotonyStack<int, greater_equal<int>>(v.begin()+1, v.end()-1);
        auto msr = MonotonyStack<int, greater_equal<int>>(v.rbegin()+1, v.rend()-1).reverse();
        SparseTable<ll, greater<ll>> stpre(pre.begin(), pre.end());
        SparseTable<ll, greater<ll>> stsuf(suf.begin(), suf.end());
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            int l=msl.get()[i-1]+1, r=msr.get()[i-1]+1;
            if(stpre.query(i, r-1)-pre[i-1]>v[i]||stsuf.query(l+1, i)-suf[i+1]>v[i])
            {
                flag = false;
                break;
            }
        }
        cout<<(flag?"YES":"NO")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
