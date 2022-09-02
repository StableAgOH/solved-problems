#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int a,b;
    cin>>a>>b;
    ll mul = 1;
    if(a+b==0) cout<<1<<endl;
    else
    {
        for(int i=2;i<=a+b;i++)
            mul *= i;
        cout<<mul<<endl;
    }
    return 0;
}