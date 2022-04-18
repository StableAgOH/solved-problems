#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <queue>
#include <cstring>
#include <tuple>
const int maxn = 1005;
typedef tuple<int,int,int> tp3;
int board[maxn][maxn];
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
    memset(board, 0x3f, sizeof(board));
    int n,m,q;
    cin>>n>>m>>q;
    int x,y;
    cin>>x>>y;
    static queue<tp3> que;
    que.emplace(x,y,0);
    while(!que.empty())
    {
        auto [p,q,c] = que.front();
        que.pop();
        if(p<1||p>n||q<1||q>m) continue;
        if(board[p][q]<=c) continue;
        board[p][q] = c;
        que.emplace(p-2,q-1,c+1);
        que.emplace(p-2,q+1,c+1);
        que.emplace(p+2,q-1,c+1);
        que.emplace(p+2,q+1,c+1);
        que.emplace(p-1,q-2,c+1);
        que.emplace(p-1,q+2,c+1);
        que.emplace(p+1,q-2,c+1);
        que.emplace(p+1,q+2,c+1);
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<(board[a][b]==0x3f3f3f3f?-1:board[a][b])<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
