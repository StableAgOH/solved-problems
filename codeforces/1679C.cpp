#include <iostream>
#include <chrono>
using namespace std;
//==========================================
const int maxn = 1e5+5;
int f1[maxn], f2[maxn];
class BIT
{
private:
    int n;
    int c[maxn];
    inline int lowbit(int x) { return x&-x; }
public:
    BIT(int n) { this->n = n; }
    void modify(int p,int x)
    {
        for(int i=p;i<=n;i+=lowbit(i))
            c[i] += x;
    }
    int query(int p)
    {
        int sum = 0;
        for(int i=p;i;i-=lowbit(i))
            sum += c[i];
        return sum;
    }
};

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
    int n,q;
    cin>>n>>q;
    static BIT t1(n), t2(n);
    while(q--)
    {
        int opt,a,b,c,d;
        cin>>opt>>a>>b;
        switch(opt)
        {
        case 1:
            f1[a]++;
            if(f1[a]==1) t1.modify(a,1);
            f2[b]++;
            if(f2[b]==1) t2.modify(b,1);
            break;
        case 2:
            f1[a]--;
            if(f1[a]==0) t1.modify(a,-1);
            f2[b]--;
            if(f2[b]==0) t2.modify(b,-1);
            break;
        case 3:
            cin>>c>>d;
            int x = t1.query(c)-t1.query(a-1);
            int y = t2.query(d)-t2.query(b-1);
            if(x==c-a+1||y==d-b+1)
                cout<<"Yes"<<'\n';
            else cout<<"No"<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}