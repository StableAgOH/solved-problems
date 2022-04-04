#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
vector<int> ans;
void solve(int a,int b)
{
    if(a==1) return;
    int tmp = a/b;
    ans.push_back(tmp);
    a -= tmp*b;
    solve(b,a);
}
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
    int t;
    cin>>t;
    while(t--)
    {
        ans.clear();
        int a,b;
        cin>>a>>b;
        if(a==1) cout<<"1 0 "<<b<<endl;
        else
        {
            solve(a,b);
            cout<<ans.size()-1<<' ';
            for(auto i : ans) cout<<i<<' ';
            cout<<endl;
        }
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
