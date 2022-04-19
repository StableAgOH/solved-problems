#include<cstdio>
#include<stack>

using namespace std;

stack<int> sn1;
stack<int> sn2;

int main()
{
	char c;
	char f;
	bool b = false;
	while(scanf("%c",&c)!=EOF)
	{
		if('0'<=c&&c<=(int)'9'&&!b)
		{
			sn1.push(c-'0');
		}
		else if('0'<=c&&c<='9')
		{
			sn2.push(c-'0');
		}
		else if( c == '.'|| c == '/')
		{
			b = true;
			f = c;
		}
		else if( c == '%')
		{
			b = true;
			f = c;
			break;
		}
	}
	unsigned long long i1=0,i2=0;
	while(!sn1.empty())
	{
	    i1=i1*10+sn1.top();
	    sn1.pop();
    }
	if(!b)
	{
	    printf("%lld", i1);
	}
	else if(f == '/')
	{
		while(!sn2.empty())
		{
			i2=i2*10+sn2.top();
			sn2.pop();
		}
		printf("%lld%c%lld",i1,f,i2);
	}
	else if(f == '.')
	{
		while(!sn2.empty())
		{
			i2=i2*10+sn2.top();
			sn2.pop();
		}
		while(i2!=0&&i2%10==0)
		{
			i2/=10;
		}
		printf("%lld%c%lld",i1,f,i2);
	}
	else
	{
		printf("%lld%c",i1,f);
	}
	return 0;
}