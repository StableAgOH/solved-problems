#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <tuple>
typedef tuple<int,int,int,int,int,int,int,int,int,int> tp10;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    int ans=0;
    if(n<10||n>30) cout<<0<<endl;
    else 
    {
        vector<tp10> v;
        for(int a=1;a<=3;a++)
            for(int b=1;b<=3;b++)
                for(int c=1;c<=3;c++)
                    for(int d=1;d<=3;d++)
                        for(int e=1;e<=3;e++)
                            for(int f=1;f<=3;f++)
                                for(int g=1;g<=3;g++)
                                    for(int h=1;h<=3;h++)
                                        for(int i=1;i<=3;i++)
                                            for(int j=1;j<=3;j++)
                                                if(a+b+c+d+e+f+g+h+i+j==n)
                                                    v.emplace_back(a,b,c,d,e,f,g,h,i,j);
        cout<<v.size()<<endl;
        for(auto& t : v)
        {
            apply([](auto&&... ts) { ((cout<<ts<<' '), ...); }, t);
            cout<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
