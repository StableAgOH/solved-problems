#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <cmath>
vector<int> v;
int cnt;
bool isprime(int x)
{
    if(x==1) return false;
    for(int i=2,to=sqrt(x);i<=to;i++)
        if(x%i==0) return false;
    return true;
}
int n;
bool mp[25];
void dfs(int k,int cur,int sum)
{
    if(k==1)
    {
        if(isprime(sum)) cnt++;
        return;
    }
    for(int i=cur+1;i<n;i++)
        dfs(k-1, i, sum+v[i]);
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        dfs(k, i, v[i]);
        ans+=cnt;
        cnt=0;
    }
    cout<<ans<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
