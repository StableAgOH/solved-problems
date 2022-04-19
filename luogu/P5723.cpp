#include <iostream>
#include <chrono>
using namespace std;
//==========================================
bool isprime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}
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
    int l;
    cin>>l;
    int sum=0, cnt=0;
    for(int i=2;i<=l;i++)
    {
        if(isprime(i))
        {
            sum += i;
            if(sum>l) break;
            cout<<i<<'\n';
            cnt++;
        }
    }
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
