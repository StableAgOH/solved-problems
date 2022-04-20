#include <iostream>
#include <chrono>
using namespace std;
//==========================================
int judge(int a,int b)
{
    switch(a)
    {
    case 0:
        if(b==0) return 0;
        if(b==1||b==4) return -1;
        else return 1;
    case 1:
        if(b==1) return 0;
        if(b==2||b==4) return -1;
        else return 1;
    case 2:
        if(b==2) return 0;
        if(b==0||b==3) return -1;
        else return 1;
    case 3:
        if(b==3) return 0;
        if(b==0||b==1) return -1;
        else return 1;
    case 4:
        if(b==4) return 0;
        if(b==2||b==3) return -1;
        else return 1;
    }
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
    int n,a,b;
    cin>>n>>a>>b;
    int ap=0, bp=0;
    int aaa=-1, bbb=-1;
    int aa[a], bb[b];
    for(int i=0;i<a;i++) cin>>aa[i];
    for(int i=0;i<b;i++) cin>>bb[i];
    for(int i=0;i<n;i++)
    {
        aaa++; bbb++;
        if(aaa==a) aaa = 0;
        if(bbb==b) bbb = 0;
        switch(judge(aa[aaa], bb[bbb]))
        {
            case 1: ap++; break;
            case -1: bp++; break;
            case 0: break;
        }
    }
    cout<<ap<<' '<<bp<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
