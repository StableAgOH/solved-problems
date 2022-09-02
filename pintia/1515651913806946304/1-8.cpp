#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e6+1e3+5;
bool isprime[maxn];
vector<int> pri;
bool vis[maxn];
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    for(int i=2;i<=1e6+1e3;i++)
    {
        if(!vis[i])
        {
            pri.push_back(i);
            isprime[i] = true;
        }
        for(auto j : pri)
        {
            if(i*j>1e6+1e3) break;
            vis[i*j] = true;
            if(i%j==0) break;
        }
    }
    int l,r;
    cin>>l>>r;
    auto b = lower_bound(pri.begin(), pri.end(), l)-pri.begin();
    auto p = upper_bound(pri.begin(), pri.end(), r)-pri.begin();
    int cnt = 0;
    for(int i=b;i<p;i++)
    {
        for(int j=i+1;j<p;j++)
        {
            for(int k=j+1;k<p;k++)
            {
                if(isprime[pri[i]*pri[j]+pri[k]]&&isprime[pri[j]*pri[k]+pri[i]]&&isprime[pri[k]*pri[i]+pri[j]])
                    cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
