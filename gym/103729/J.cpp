#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
#include <string>
typedef pair<int,int> pii;
typedef long long ll;
class StringHash
{
private:
    int mod;
    vector<ll> ppow, hpre;
public:
    StringHash(const string& s, int p=114514, int mod=998244353)
    {
        this->mod = mod;
        this->ppow.push_back(1);
        this->hpre.push_back(0);
        for(int i=1;i<=s.length();i++)
        {
            this->ppow.push_back(this->ppow[i-1]*p%mod);
            this->hpre.push_back(hpre[i-1]*p%mod+s[i-1]%mod);
        }
    }
    int get(int l,int r)
    {
        if(l>r) return -1;
        return (hpre[r]-hpre[l-1]*this->ppow[r-l+1]%mod+mod)%mod;
    }
};
pii solve(const string& s)
{
    int n = s.length();
    string r = s;
    reverse(r.begin(), r.end());
    StringHash sh(s), sr(r);
    for(int i=1;i+i<=n;i++)
        if(sh.get(1,i)==sh.get(n-i+1,n)&&sh.get(i+1,n-i)==sr.get(i+1,n-i))
            return {1, i};
    for(int i=1;i+i<=n;i++)
        if(sh.get(1,i)==sh.get(i+1,i+i)&&sh.get(i+i+1,n)==sr.get(1,n-i-i))
            return {i+1, n};
    for(int i=1;i+i<=n;i++)
        if(sr.get(1,i)==sr.get(i+1,i+i)&&sr.get(i+i+1,n)==sh.get(1,n-i-i))
            return {1, n-i};
    return {-1, -1};
}
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
    string s;
    cin>>s;
    int l=0, r=s.length()-1;
    while(s[l]==s[r]&&l<r) l++, r--;
    if(l>=r) cout<<1<<' '<<s.length()<<endl;
    else
    {
        s = s.substr(l, r-l+1);
        auto res = solve(s);
        cout<<res.first+l<<' '<<res.second+l<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
