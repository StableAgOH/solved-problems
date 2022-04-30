#include <iostream>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n,v;
    cin>>n>>v;
    cout<<n/v<<endl;
    return 0;
}