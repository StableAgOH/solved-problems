#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int sum = count(s.begin(), s.end(), '1');
        int cnt = 0;
        list<int> ls;
        for(size_t i=0;i<s.length();i++)
        {
            if(s[i]=='0') cnt++;
            else
            {
                if(cnt) ls.push_back(cnt);
                cnt = 0;
            }
        }
        if(cnt) ls.push_back(cnt);
        ll ans = sum;
        for(int i=0;i<k;i++)
        {
            sum += ls.size()-1;
            ans += sum;
            for(auto it=ls.begin();it!=ls.end();)
            {
                *it -= 1;
                auto p = it++;
                if(!*p) ls.erase(p);
                if(it==ls.end()) break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
