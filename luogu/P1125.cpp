#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
int ch[155];
bool isprime(int x)
{
    if(x==0||x==1) return false;
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
    string s;
    cin>>s;
    for(auto c : s) ch[(int)c]++;
    int minn=0x3f3f3f3f, maxn=0xcfcfcfcf;
    for(int i='a';i<='z';i++)
    {
        minn=min(minn,ch[i]==0?0x3f3f3f3f:ch[i]);
        maxn=max(maxn,ch[i]);
    }
    int tmp = maxn-minn;
    if(isprime(tmp))
    {
        cout<<"Lucky Word"<<endl;
        cout<<tmp<<endl;
    }
    else
    {
        cout<<"No Answer"<<endl;
        cout<<0<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
