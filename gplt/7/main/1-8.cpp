#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 295;
typedef pair<int,int> pii;
vector<pii> v;
int arr[maxn];
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n,k,s;
    cin>>n>>k>>s;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>=175)
        {
            if(b>=s) cnt++;
            else arr[a]++;
        }
    }
    for(int i=175;i<=290;i++)
        cnt += min(arr[i], k);
    cout<<cnt<<endl;
    return 0;
}