#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
#include <cmath>
const int maxn = 1e5+5;
int a[maxn<<1];
vector<int> v;
inline int getid(int x) { return lower_bound(v.begin(),v.end(),x)-v.begin()+1; }
int id[maxn<<1];
int pos[maxn<<1];
struct Q { int l,r,p; };
vector<Q> q;
bool ans[maxn];
int16_t res;
int cnt1[maxn<<1], cnt2[maxn<<1];
void Add(int x)
{
    bool flag = cnt1[id[x]]&&cnt2[id[x]];
    if(x&1) cnt1[id[x]]++;
    else cnt2[id[x]]++;
    if(!flag&&cnt1[id[x]]&&cnt2[id[x]]) res++;
}
void Sub(int x)
{
    bool flag = cnt1[id[x]]&&cnt2[id[x]];
    if(x&1) cnt1[id[x]]--;
    else cnt2[id[x]]--;
    if(flag&&!(cnt1[id[x]]&&cnt2[id[x]])) res--;
}
bool cmp(Q& a,Q& b)
{
    if(pos[a.l]<pos[b.l]) return true;
    else if(pos[a.l]>pos[b.l]) return false;
    else return pos[a.r]>pos[b.r];
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
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
    {
        int p = i<<1;
        cin>>a[p-1];
        a[p] = a[p-1]^x;
        v.push_back(a[p-1]);
        v.push_back(a[p]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n<<1;i++)
        id[i] = getid(a[i]);
    int siz = sqrt(n<<1);
    for(int i=1;i<=n<<1;i++)
        pos[i] = i/siz;
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        q.push_back((Q){l*2-1,r*2,i});
    }
    sort(q.begin(),q.end(),cmp);
    int l=1,r=0;
    for(int i=0;i<m;i++)
    {
        int x=q[i].l, y=q[i].r;
        if(x+1==y) continue;
        while(l<x)
            Sub(l++);
        while(l>x)
            Add(--l);
        while(r<y)
            Add(++r);
        while(r>y)
            Sub(r--);
        ans[q[i].p] = res;
    }
    for(int i=0;i<m;i++)
        cout<<(ans[i]?"yes":"no")<<'\n';
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
