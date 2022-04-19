#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
const int maxn = 1e4+5;
bool vis[maxn];
vector<int> pri;
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
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]) pri.push_back(i);
        for(auto j : pri)
        {
            if(i*j>n) break;
            vis[i*j] = true;
            if(i%j==0) break;
        }
    }
    for(int i=4;i<=n;i+=2)
    {
        for(auto j : pri)
        {
            if(!vis[i-j])
            {
                cout<<i<<'='<<j<<'+'<<i-j<<'\n';
                break;
            }
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
