#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
typedef pair<int,int> pii;
int a[201];
int mem[201][201];
int dfs(int l, int r)
{
    if(l==r) return mem[l][l]=0;
    if(mem[l][r]) return mem[l][r];
    int max=0xcfcfcfcf;
    for(int k=l;k<r;k++)
        max=std::max(max,dfs(l,k)+dfs(k+1,r)+a[l]*a[k+1]*a[r+1]);
    return mem[l][r]=max;
}
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
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n] = a[i];
    }
    int mx = 0xcfcfcfcf;
    for(int i=1;i<=n;i++)
        mx=max(mx,dfs(i,i+n-1));
    cout<<mx<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
