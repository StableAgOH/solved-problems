#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(s.length()==1) cout<<"1 2"<<endl;
        else if(s.length()==2)
        {
            if(s[0]==s[1]) cout<<"2 8"<<endl;
            else cout<<"2 6"<<endl;
        }
        else 
        {
            bool eq = count(s.begin(),s.end(),s.front())==s.length();
            if(eq) cout<<"2 4"<<endl;
            else cout<<"2 2"<<endl;
        }
    }
    return 0;
}