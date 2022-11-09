#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
bool in_line(const pii& p, const pii& q, const pii& r)
{
    return (q.second-p.second)*(r.first-q.first)==(q.first-p.first)*(r.second-q.second);
}
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
        int n;
        cin>>n;
        vector<pii> v;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v.emplace_back(x,y);
        }
        if(n<5) cout<<"NO"<<'\n';
        else
        {
            vector<pii> w;
            auto p = v[0];
            auto q = v[1];
            w.emplace_back(p);
            w.emplace_back(q);
            bool flag = false;
            for(int i=2;i<n;i++)
            {
                auto r = v[i];
                if(in_line(p,q,r)) continue;
                w.push_back(r);
                if(i==2) w.push_back(v[i+1]), w.push_back(v[i+2]);
                else if(i==3) w.push_back(v[i-1]), w.push_back(v[i+1]);
                else w.push_back(v[i-1]), w.push_back(v[i-2]);
                flag = true;
                break;
            }
            if(!flag) cout<<"NO"<<'\n';
            else
            {
                for(int i=0;i<5;i++)
                {
                    set<pii> s;
                    for(int j=0;j<5;j++)
                    {
                        if(j==i) continue;
                        auto p = w[j].first-w[i].first;
                        auto q = w[j].second-w[i].second;
                        auto g = gcd(p,q);
                        p /= g;
                        q /= g;
                        pii vet = {p, q};
                        if(s.find(vet)!=s.end()) break;
                        else s.insert(vet);
                    }
                    if(s.size()==4)
                    {
                        cout<<"YES"<<'\n';
                        cout<<w[i].first<<' '<<w[i].second<<'\n';
                        for(int j=0;j<5;j++)
                        {
                            if(j==i) continue;
                            cout<<w[j].first<<' '<<w[j].second<<'\n';
                        }
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
