#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const string p = "Timru";
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        sort(s.begin(), s.end());
        cout<<(s==p?"YES":"NO")<<endl;
    }
    return 0;
}