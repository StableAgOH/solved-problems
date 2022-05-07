#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <algorithm>
#include <cmath>
const int maxn = 105;
int a[maxn];
int n;
char g[500][500];
void draw(int c,int p,int x,int y)
{
    if(c<=1) return;
    int _=x, __=y;
    for(int i=1;i<=c/2;i++)
    {
        for(int j=1;j<=c-i-1;j++) g[_][__++] = '*';
        if(i==1)
        {
            if(p>n)
            {
                g[_][__++] = '-';
                g[_][__++] = '-';
            }
            else 
            {
                g[_][__++] = a[p]/10+'0';
                g[_][__++] = a[p]%10+'0';
            }
        }
        else 
        {
            g[_][__++] = '/';
            for(int j=1;j<=(i-1)*2;j++) g[_][__++] = '*';
            g[_][__++] = '\\';
        }
        for(int j=1;j<=c-i-1;j++) g[_][__++] = '*';
        _++;
        __ = y;
    }
    draw(c/2, p<<1, x+c/2, y);
    draw(c/2, p<<1|1, x+c/2, y+c);
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
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    make_heap(a+1, a+1+n, greater<int>());
    while(m--)
    {
        string s;
        cin>>s;
        if(s=="top") cout<<a[1]<<endl<<endl;
        else if(s=="pop")
        {
            pop_heap(a+1, a+1+n, greater<int>());
            n--;
        }
        else if(s=="push")
        {
            cin>>a[++n];
            push_heap(a+1, a+1+n, greater<int>());
        }
        else if(s=="draw")
        {
            int b = log2(n)+1;
            int q = 1<<b;
            draw(q,1,1,1);
            for(int i=1;i<=q-1;i++)
            {
                for(int j=1;j<=q*2-2;j++)
                    cout<<(g[i][j]?g[i][j]:'*');
                cout<<endl;
            }
            cout<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
