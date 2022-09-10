#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct S { int c,a,b; };
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<queue<int>> v(k+1);
        vector<S> cnt(n+1);
        queue<pair<int,int>> q;
        for(int i=1;i<=k;i++)
        {
            int l;
            cin>>l;
            for(int j=0;j<l;j++)
            {
                int x;
                cin>>x;
                if(!j)
                {
                    cnt[x].c++;
                    if(cnt[x].a)
                    {
                        cnt[x].b = i;
                        q.push({cnt[x].a,cnt[x].b});
                    }
                    else cnt[x].a = i;
                }
                v[i].emplace(x);
            }
        }
        int cur = 0;
        while(!q.empty())
        {
            auto s = q.front();
            q.pop();
            v[s.first].pop();
            if(!v[s.first].empty())
            {
                int t = v[s.first].front();
                cnt[t].c++;
                if(cnt[t].a)
                {
                    cnt[t].b = s.first;
                    if(cnt[t].c==2) q.push({cnt[t].a, cnt[t].b});
                }
                else cnt[t].a = s.first;
            }
            v[s.second].pop();
            if(!v[s.second].empty())
            {
                int t = v[s.second].front();
                cnt[t].c++;
                if(cnt[t].a)
                {
                    cnt[t].b = s.second;
                    if(cnt[t].c==2) q.push({cnt[t].a, cnt[t].b});
                }
                else cnt[t].a = s.second;
            }
            cur = !cur;
        }
        cout<<(cur?"Kelly":"Nacho")<<'\n';
    }
    return 0;
}
