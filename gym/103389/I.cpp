#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 55;
int mp[maxn][maxn];
const vector<pair<int,int>> d = {
    {-1,0},
    {-1,1},
    {0,1},
    {1,1},
    {1,0},
    {1,-1},
    {0,-1},
    {-1,-1},
};
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    int curx, cury, curv=0;
    int curd = 0;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            auto c = s[j];
            if(c=='#') mp[i][j+1] = 1;
            else if(c=='*') curx=i, cury=j+1;
        }
    }
    int q;
    cin>>q;
    string s;
    cin>>s;
    for(auto c : s)
    {
        switch(c)
        {
        case 'L': curd--; if(curd==-1) curd = 7; break;
        case 'R': curd++; if(curd==8) curd = 0; break;
        case 'U': curv++; break;
        case 'D': if(curv) curv--; break;
        }
        bool bc = false;
        for(int i=0;i<curv;i++)
        {
            int x = curx+d[curd].first;
            int y = cury+d[curd].second;
            if(x<1||x>n||y<1||y>m) bc = true;
            else if(mp[x][y]) bc = true;
            else if(curd%2)
            {
                if(curd==1&&mp[curx-1][cury]&&mp[curx][cury+1]) bc = true;
                else if(curd==3&&mp[curx+1][cury]&&mp[curx][cury+1]) bc = true;
                else if(curd==5&&mp[curx+1][cury]&&mp[curx][cury-1]) bc = true;
                else if(curd==7&&mp[curx-1][cury]&&mp[curx][cury-1]) bc = true;
            }
            if(bc)
            {
                curv = 0;
                break;
            }
            curx=x, cury=y;
        }
        if(bc) cout<<"Crash! "<<curx<<' '<<cury<<'\n';
        else cout<<curx<<' '<<cury<<'\n';
    }
    return 0;
}