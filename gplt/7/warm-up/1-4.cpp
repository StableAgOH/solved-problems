#include <iostream>
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
        int opt,h,w;
        cin>>opt>>h>>w;
        if(opt)
        {
            if(h>130)
            {
                cout<<"ni li hai!"<<' ';
            }
            else if(h==130)
            {
                cout<<"wan mei!"<<' ';
            }
            else
            {
                cout<<"duo chi yu!"<<' ';
            }
            if(w>27)
            {
                cout<<"shao chi rou!";
            }
            else if(w==27)
            {
                cout<<"wan mei!";
            }
            else
            {
               cout<<"duo chi rou!"; 
            }
            cout<<endl;
        }
        else 
        {
            if(h>129)
            {
                cout<<"ni li hai!"<<' ';
            }
            else if(h==129)
            {
                cout<<"wan mei!"<<' ';
            }
            else
            {
                cout<<"duo chi yu!"<<' ';
            }
            if(w>25)
            {
                cout<<"shao chi rou!";
            }
            else if(w==25)
            {
                cout<<"wan mei!";
            }
            else
            {
               cout<<"duo chi rou!"; 
            }
            cout<<endl;
        }
    }
    return 0;
}
