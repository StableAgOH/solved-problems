#include <iostream>
#include <chrono>
using namespace std;
//==========================================
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int num, newn;
    cin>>num;
    if(num>=0)
    {
        newn = 0;
        while(num)
        {
            newn = newn*10+num%10;
            num /= 10;
        }
    }
    else
    {
        num = -num;
        newn = 0;
        while(num)
        {
            newn = newn*10+num%10;
            num /= 10;
        }
        cout<<'-';
    }
    cout<<newn<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
