#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cstring>
#include <deque>
const int maxn = 5e5+5;
typedef long long ll;
int n,d,k;
int x[maxn], s[maxn];
ll dp[maxn];
deque<ll> dq;
bool check(int g)
{
    dq.clear();
    memset(dp, 0xcf, sizeof(dp));
    dp[0]=0;
    int l=d+g, r=d-g>1?d-g:1;
    int p=0;
    for(int i=1;i<=n;i++)
    {
        while(!dq.empty()&&x[dq.front()]+l<x[i])
            dq.pop_front();
        while(x[p]<x[i]-l)
            ++p;
        while(x[p]<=x[i]-r)
        {
            while (!dq.empty()&&dp[dq.back()]<dp[p])
                dq.pop_back();
            dq.push_back(p++);
        }
        dp[i]=dq.empty()?0xcfcfcfcfcfcfcfcf:dp[dq.front()]+s[i];
        if(dp[i]>=k) return true;
    }
    return false;
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
    cin>>n>>d>>k;
    ll sum = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>s[i];
        if(s[i]>0) sum += s[i];
    }
    if(sum<k) cout<<-1<<endl;
    else 
    {
        int l=0, r=maxn;
        while(l<r)
        {
            int m = (l+r)>>1;
            if(check(m)) r=m;
            else l=m+1;
        }
        cout<<l<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}