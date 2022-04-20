#include <cstdio>
#include <iostream>
using namespace std;
int main(void)
{
    int n, num;
    bool bf = true;
    cin>>n;
    n++;
    while(n--)
    {
        if(n)
        {
            scanf("%d",&num);
            if(num) 
            {
                if(num>0)
                {
                    if(num==1)
                    {
                        if(bf)
                        {
                            if(n!=1) printf("x^%d",n);
                            else printf("x");
                            bf = false;
                        }
                        else
                        {
                            if(n==1) printf("+x");
                            else printf("+x^%d",n);
                        }
                    }
                    else
                    {
                        if(bf)
                        {
                            if(n!=1) printf("%dx^%d",num,n);
                            else printf("%dx",num);
                            bf = false;
                        }
                        else
                        {
                            if(n!=1) printf("+%dx^%d",num,n);
                            else printf("+%dx",num);
                        }
                    }
                }
                else
                {
                    if(num!=-1)
                    {
                        if(n!=1)printf("%dx^%d",num,n);
                        else printf("%dx",num);
                        bf=false;
                    }
                    else
                    {
                        if(n!=1) printf("-x^%d",n);
                        else printf("-x");
                        bf=false;
                    }
                }
            }
        }
        else
        {
            scanf("%d",&num);
            if(num>0)printf("+%d",num);
            else if(!num);
            else printf("%d",num);
        }
    }
    cout<<endl;
    // system("pause");
    return 0;
}