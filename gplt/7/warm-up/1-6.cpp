#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        for(int i=0;i<s.length()-1;i++)
        {
            if(isupper(s[i]))
            {
                if(s[i+1]!=tolower(s[i])&&s[i+1]!=s[i]+1)
                {
                    cout<<"N"<<endl;
                    goto nxt;
                }
            }
            else 
            {
                if(s[i+1]!=toupper(s[i])&&s[i+1]!=s[i]-1)
                {
                    cout<<"N"<<endl;
                    goto nxt;
                }
            }
        }
        cout<<"Y"<<endl;
        nxt:;
    }
    return 0;
}
