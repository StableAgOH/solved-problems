#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
#include <vector>
#include <algorithm>
const int maxn = 5005;
int query(int u)
{
    cout<<"dfn "<<u<<endl;
    int ret; cin>>ret; return ret;
}
int query(int u,int v)
{
    cout<<"dis "<<u<<' '<<v<<endl;
    int ret; cin>>ret; return ret;
}
void del() { cout<<"del"<<endl; }
void submit(int x) { cout<<"! "<<x<<endl; exit(); }
void input(vector<int>& v)
{
    int n; cin>>n; v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
}
signed main(signed argc, char const *argv[])
{
    c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    //======================================
    for(int _=1;_<=140;_++)
    {
        vector<int> d;
        vector<pair<int,int>> d1;
        input(d);
        if(d.size()==1) submit(0);
        int h=0,t=0;
        for(int i=1;i<=d.size();i++)
        {
            if(d[i-1]==1)
            {
                d1.emplace_back(0, i);
                if(!h) h=i;
                else if(!t) t=i;
            }
        }
        if(d1.size()==2) submit(query(h,t));
        else if(d1.size()*2<=141-_)
        {
            for(auto &p : d1) p.first = query(p.second);
            sort(d1.begin(), d1.end());
            int ans = query(d1.front().second, d1.back().second);
            for(int i=0;i<d1.size()-1;i++)
                ans+=query(d1[i].second, d1[i+1].second);
            submit(ans/2);
        }
        else del();
    }
    //======================================
    exit();
}