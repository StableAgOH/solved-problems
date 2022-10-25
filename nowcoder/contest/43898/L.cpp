#include <iostream>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<a*b*c*d<<'\n';
    }
    return 0;
}
