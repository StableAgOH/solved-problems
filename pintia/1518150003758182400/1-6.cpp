#include <iostream>
#include <string>
using namespace std;
string solve(string a)
{
    string s;
    for (int i = 1; i < a.length(); i++) {
        if (a[i] % 2 == a[i-1] % 2) {
            s += max(a[i], a[i-1]);
        }
    }
    return s;
}
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    string s1, s2;
    cin>>s1>>s2;
    s1 = solve(s1);
    s2 = solve(s2);
    if(s1==s2) cout<<s1<<endl;
    else cout<<s1<<endl<<s2<<endl;
    return 0;
}