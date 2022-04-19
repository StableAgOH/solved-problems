#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
const string num[10][5] = {
    {"XXX","X.X","X.X","X.X","XXX"},
    {"..X","..X","..X","..X","..X"},
    {"XXX","..X","XXX","X..","XXX"},
    {"XXX","..X","XXX","..X","XXX"},
    {"X.X","X.X","XXX","..X","..X"},
    {"XXX","X..","XXX","..X","XXX"},
    {"XXX","X..","XXX","X.X","XXX"},
    {"XXX","..X","..X","..X","..X"},
    {"XXX","X.X","XXX","X.X","XXX"},
    {"XXX","X.X","XXX","..X","XXX"}
};
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<5;i++)
    {
        for(auto it=s.begin();it!=s.end();it++)
        {
            int x = *it-'0';
            cout<<num[x][i];
            if(it!=s.end()-1) cout<<'.';
        }
        cout<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
