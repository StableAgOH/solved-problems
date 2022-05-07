#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
#include <cstring>
const int maxn = 2e5+5;
typedef long long ll;
int a[maxn];
ll c[maxn];
int n;
inline int lowbit(int x) { return x&-x; }
void modify(int p,int x)
{
    for(int i=p;i<=n;i+=lowbit(i))
        c[i] += x;
}
ll query(int p)
{
    ll sum = 0;
    for(int i=p;i;i-=lowbit(i))
        sum += c[i];
    return sum;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        memset(c, 0, sizeof(c));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            modify(i, a[i]);
        }
        int q;
        cin>>q;
        while(q--)
        {
            int opt,p,x;
            cin>>opt>>p;
            if(opt==1)
            {
                cin>>x;
                modify(p, x-a[p]);
                a[p] = x;
            }
            else 
            {
                int l=0, r=n;
                while(r-l>5)
                {
                    int m = (l+r)>>1;
                    if(p>=query(m)) l = m;
                    else r = m-1;
                }
                for(int i=r;i>=l;i--) if(p>=query(i))
                {
                    cout<<i<<' ';
                    break;
                }
                cout<<ll(ceil(double(query(n))/p))<<endl;
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
