#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <unordered_map>
typedef long long ll;
ll hs(const vector<int>& v)
{
    ll sum=0, mul=1;
    for(int i=v.size()-1;i>=0;i--,mul*=3)
        sum += v[i]*mul;
    return sum;
}
unordered_map<ll,ll> mp;
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
    int n,k;
    cin>>n>>k;
    vector<vector<int>> cards(n, vector<int>(k));
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            cin>>cards[i][j];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            vector<int> v(k);
            for(int l=0;l<k;l++)
            {
                if(cards[i][l]==cards[j][l]) v[l] = cards[i][l];
                else v[l] = 3-cards[i][l]-cards[j][l];
            }
            mp[hs(v)]++;
        }
    }
    ll sum = 0;
    for(auto& v : cards)
    {
        auto it = mp.find(hs(v));
        if(it==mp.end()) continue;
        sum += it->second*(it->second-1)/2;
    }
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
