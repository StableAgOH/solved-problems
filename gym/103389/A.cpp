#include <iostream>
using namespace std;
const int maxn = 15;
int k[maxn];
int main()
{
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int n,x,y;
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++) cin>>k[i];
    int m;
    cin>>m;
    bool bl=true, br=true;
    int l=x, r=x;
    for(int i=1;i<=m;i++)
    {
        int p;
        cin>>p;
        if(bl)
        {
            if(!br) break;
            if(l==1||k[l-1]!=p) bl = false;
            l--;
        }
        if(br)
        {
            if(!bl) break;
            if(r==n||k[r+1]!=p) br = false;
            r++;
        }
    }
    if(bl&&br) cout<<"Unsure"<<endl;
    else if(bl)
    {
        if(y<x) cout<<"Right"<<endl;
        else cout<<"Wrong"<<endl;
    }
    else if(br)
    {
        if(y>x) cout<<"Right"<<endl;
        else cout<<"Wrong"<<endl;
    }
    return 0;    
}