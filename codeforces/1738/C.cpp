#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <cstring>
#include <functional>
int mp[2][105][105];
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        memset(mp, 0, sizeof(mp));
        int n;
        cin>>n;
        int x=0, y=0;
        for(int i=0;i<n;i++)
        {
            int z;
            cin>>z;
            if(z&1) x++;
            else y++;
        }
        function<bool(int,int,int)> dfs = [&](int a,int b,int c) {
            if(!b&&!c) return !a;
            if(mp[a][b][c]) return mp[a][b][c]==1;
            bool ret;
            if(!b)
            {
                if(c==1) ret = !a;
                else ret = dfs(a,b,c-2);
            }
            else if(!c)
            {
                if(b==1) ret = a;
                else ret = dfs(a^1,b-2,c);
            }
            else
            {
                if(b==1&&c==1) ret = true;
                else if(b==1) ret = dfs(a^1,b-1,c-1)||(dfs(a,b-1,c-1)&&dfs(a,b,c-2));
                else if(c==1) ret = dfs(a,b-1,c-1)||(dfs(a^1,b-2,c)&&dfs(a^1,b-1,c-1));
                else ret = (dfs(a,b-1,c-1)&&dfs(a,b,c-2))||(dfs(a^1,b-1,c-1)&&dfs(a^1,b-2,c));
            }
            if(ret) mp[a][b][c] = 1;
            else mp[a][b][c] = 2;
            return ret;
        };
        cout<<(dfs(0,x,y)?"Alice":"Bob")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
