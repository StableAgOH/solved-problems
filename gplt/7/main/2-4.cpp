#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
const int maxn = 505;
vector<int> male, female;
int dis[maxn][maxn];
#include <cstring>
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    memset(dis, 0x3f, sizeof(dis));
    int n;
    cin>>n;
    for(int u=1;u<=n;u++)
    {
        dis[u][u] = 0;
        string s;
        int k;
        cin>>s>>k;
        if(s=="F") female.push_back(u);
        else male.push_back(u);
        for(int j=0;j<k;j++)
        {
            cin>>s;
            auto p = s.find(':');
            int v = stoi(s.substr(0, p));
            int w = stoi(s.substr(p+1));
            dis[u][v] = w;
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    vector<int> ma, fa;
    int mxm=0x3f3f3f3f, mxf=0x3f3f3f3f;
    for(auto i : male)
    {
        int mx = -1;
        for(auto j : female) mx = max(mx, dis[j][i]);
        if(mx<mxm)
        {
            ma.clear();
            ma.push_back(i);
            mxm = mx;
        }
        else if(mx==mxm) ma.push_back(i);
    }
    for(auto i : female)
    {
        int mx = -1;
        for(auto j : male) mx = max(mx, dis[j][i]);
        if(mx<mxf)
        {
            fa.clear();
            fa.push_back(i);
            mxf = mx;
        }
        else if(mx==mxf) fa.push_back(i);
    }
    for(int i=0;i<fa.size();i++)
    {
        if(i) cout<<' ';
        cout<<fa[i];
    }
    cout<<endl;
    for(int i=0;i<ma.size();i++)
    {
        if(i) cout<<' ';
        cout<<ma[i];
    }
    return 0;
}