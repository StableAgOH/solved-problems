#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e4+5;
typedef long long ll;
bool vis[maxn];
vector<int> pri;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    const int p = 1e4;
    for(int i=2;i<=p;i++)
    {
        if(!vis[i]) pri.push_back(i);
        for(auto j : pri)
        {
            if((long long)i*j>p) break;
            vis[i*j] = true;
            if(i%j==0) break;
        }
    }
    ll n,k;
    cin>>n>>k;
    n--;
    if(k==2)
    {
        cout<<k+((n/2)*5+(n%2)*3)<<endl;
    }
    else
    {
        for(auto i : pri)
        {
            if(k%i!=0)
            {
                n--;
                if(i==2) cout<<k+i+((n/2)*5+(n%2)*3)<<endl;
                else cout<<k+i+((n/2)*5+(n%2)*2)<<endl;
                return 0;
            }
        }
        cout<<k+((n/2)*5+(n%2)*2)<<endl;
    }
    return 0;
}
