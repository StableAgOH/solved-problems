#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int n;
    cin>>n;
    int cnt = 0;
    string s;
    getline(cin, s);
    for(int i=0;i<n;i++)
    {
        getline(cin, s);
        cnt += count(s.begin(), s.end(),'-');
    }
    cout<<cnt<<endl;
    return 0;    
}