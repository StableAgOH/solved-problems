#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
const int maxn = 2005;
int a[maxn][maxn];
int n,m;
void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(a[i][j]==1) cout<<'+';
            else if(a[i][j]==2) cout<<'*';
            else cout<<'.';
        cout<<endl;
    }
    cout<<endl;
}
#include <queue>
#include <tuple>
typedef tuple<int,int,int,int> tp4;
int bfs(int r,int c,int x,int y)
{
    deque<tp4> q;
    q.push_back(tp4(r,c,x,y));
    int ret = 0;
    while(!q.empty())
    {
        auto t = q.front();
        q.pop_front();
        tie(r,c,x,y)=t;
        if(a[r][c]) continue;
        if(r<0||c<0||r>=n||c>=m||x<0||y<0)
            continue;
        ret+=1;
        a[r][c]=1;
        q.push_front(tp4(r-1,c,x,y));
        q.push_back(tp4(r,c-1,x-1,y));
        q.push_front(tp4(r+1,c,x,y));
        q.push_back(tp4(r,c+1,x,y-1));
    }
    return ret;
}
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int r,c,x,y;
    cin>>n>>m>>r>>c>>x>>y;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
            if(s[j]=='*')
                a[i][j]=2;
    }
    cout<<bfs(r-1,c-1,x,y)<<endl;
    //======================================
#ifdef LOCAL
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}