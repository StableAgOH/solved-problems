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
    int n,L,G,tmp1,tmp2;
    cin>>n>>L>>G;
    for(int i=0;i<n;i++)
    {
        cin>>tmp1>>tmp2;
        if(tmp1<L||tmp2<L) cout<<"Too Young"<<endl;
        else
        {
            while(tmp1>G||tmp2>G) tmp1/=2,tmp2/=2;
            if(tmp1<L||tmp2<L) cout<<"Too Young"<<endl;
            else if(tmp1!=tmp2) cout<<"Too Simple"<<endl;
            else cout<<"Sometimes Naive"<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
