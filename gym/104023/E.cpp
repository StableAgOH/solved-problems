#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
void f(int ver)
{
    cout<<"Python 3."<<ver<<" will be faster than C++"<<endl;
}
void g()
{
    cout<<"Python will never be faster than C++"<<endl;
}
int main()
{
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int x = v[n-2];
    int y = v[n-1];
    if(y>=x) g();
    else
    {
        for(int i=n+1;;i++)
        {
            int z = max(0, 2*y-x);
            if(z<k)
            {
                f(i);
                break;
            }
            else
            {
                x = y;
                y = z;
            }
        }
    }
    return 0;
}
