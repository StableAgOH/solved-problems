#include <iostream>
#include <chrono>
using namespace std;
//==========================================
bool judge(int a,int b,int c,int x)
{
    if(x==c||x==b-c) return true;
    int t = a-2*b;
    if(!t) return false;
    if((x-c)%t==0) return true;
    if((x+c-b)%t==0) return true;
    return false;
}
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,x;
        cin>>a>>b>>c>>x;
        cout<<(judge(a,b,c,x)?"Yes":"No")<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
