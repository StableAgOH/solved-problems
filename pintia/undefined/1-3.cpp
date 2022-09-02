#include <iostream>
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    bool b1 = c<a;
    bool b2 = d<a;
    if(b1||b2)
    {
        if(b1&&b2)
        {
            cout<<c<<"-N "<<d<<"-N"<<endl;
            cout<<"zhang da zai lai ba"<<endl;
        }
        else if(b1)
        {
            if(d>=b)
            {
                cout<<c<<"-Y "<<d<<"-Y"<<endl;
                cout<<"qing 2 zhao gu hao 1"<<endl;
            }
            else 
            {
                cout<<c<<"-N "<<d<<"-Y"<<endl;
                cout<<"2: huan ying ru guan"<<endl;
            }
        }
        else 
        {
            if(c>=b)
            {
                cout<<c<<"-Y "<<d<<"-Y"<<endl;
                cout<<"qing 1 zhao gu hao 2"<<endl;
            }
            else 
            {
                cout<<c<<"-Y "<<d<<"-N"<<endl;
                cout<<"1: huan ying ru guan"<<endl;
            }
        }
    }
    else 
    {
        cout<<c<<"-Y "<<d<<"-Y"<<endl;
        cout<<"huan ying ru guan"<<endl;
    }
    return 0;
}