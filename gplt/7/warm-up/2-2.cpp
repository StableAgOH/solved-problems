#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    priority_queue<tuple<int,double,string>> pq;
    for(int i=0;i<n;i++)
    {
        string s;
        int k;
        map<int,int> mp;
        cin>>s>>k;
        for(int j=0;j<k;j++)
        {
            int x;
            cin>>x;
            mp[x]++;
        }
        double aver = 0;
        for(auto [k,v] : mp)
            aver += v;
        aver /= mp.size();
        pq.emplace(mp.size(), -aver, s);
    }
    if(pq.size()==1)
    {
        cout<<get<2>(pq.top())<<" - -"<<endl;
    }
    else if(pq.size()==2)
    {
        auto s1 = get<2>(pq.top());
        pq.pop();
        auto s2 = get<2>(pq.top());
        cout<<s1<<' '<<s2<<" -"<<endl;
    }
    else 
    {
        auto s1 = get<2>(pq.top());
        pq.pop();
        auto s2 = get<2>(pq.top());
        pq.pop();
        auto s3 = get<2>(pq.top());
        cout<<s1<<' '<<s2<<' '<<s3<<endl;
    }
    return 0;
}
