#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
const double pi = 3.14159265358979;
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
    int opt;
    cin>>opt;
    switch(opt)
    {
    case 1:
        cout<<"I love Luogu!"<<endl;
        break;
    case 2:
        cout<<6<<' '<<4<<endl;
        break;
    case 3:
        cout<<3<<endl<<12<<endl<<2<<endl;
        break;
    case 4:
        printf("%.3lf\n",500.0/3);
        break;
    case 5:
        cout<<15<<endl;
        break;
    case 6:
        cout<<sqrt(6*6+9*9)<<endl;
        break;
    case 7:
        cout<<110<<endl<<90<<endl<<0<<endl;
        break;
    case 8:
        cout<<2*pi*5<<endl<<pi*5*5<<endl<<4.0/3*pi*5*5*5<<endl;
        break;
    case 9:
        cout<<22<<endl;
        break;
    case 10:
        cout<<9<<endl;
        break;
    case 11:
        cout<<100.0/3<<endl;
        break;
    case 12:
        cout<<(int)('M'-'A'+1)<<endl;
        cout<<(char)('A'+17)<<endl;
        break;
    case 13:
        cout<<(int)pow(4.0/3*pi*4*4*4+4.0/3*pi*10*10*10,1.0/3)<<endl;
        break;
    case 14:
        cout<<50<<endl;
        break;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
