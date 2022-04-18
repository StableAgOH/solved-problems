#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <set>
set<int> s;
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
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(!x)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        s.insert(x);
    }
    if(s.size()==1&&*s.begin()==0) cout<<"NO"<<endl;
    else if(s.size()==2&&*s.begin()==-*(--s.end())) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
