#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
const int maxn = 13;
typedef pair<int,int> pii;
char mp[maxn][maxn];
vector<pii> dir = {
    {-1,0}, {0,1}, {1,0}, {0,-1}
};
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int xf,yf,xc,yc;
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]=='F')
            {
                xf = i;
                yf = j;
                mp[i][j] = '.';
            }
            else if(mp[i][j]=='C')
            {
                xc = i;
                yc = j;
                mp[i][j] = '.';
            }
        }
    }
    auto curf = dir.begin();
    auto curc = dir.begin();
    for(int i=1;i<=10*10*4*10*10*4;i++)
    {
        int tgxf = xf+curf->first;
        int tgyf = yf+curf->second;
        if(mp[tgxf][tgyf]=='.') xf=tgxf, yf=tgyf;
        else
        {
            ++curf;
            if(curf==dir.end()) curf = dir.begin();
        }
        int tgxc = xc+curc->first;
        int tgyc = yc+curc->second;
        if(mp[tgxc][tgyc]=='.') xc=tgxc, yc=tgyc;
        else
        {
            ++curc;
            if(curc==dir.end()) curc = dir.begin();
        }
        if(xf==xc&&yf==yc)
        {
            cout<<i<<endl;
            goto end;
        }
    }
    cout<<0<<endl;
end:
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
