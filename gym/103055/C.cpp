#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <tuple>
#include <algorithm>
typedef tuple<int,int,int> tp3;
vector<tp3> v;
bool f(int s)
{
    vector<int> w;
    auto [x,y,z] = v[s];
    for(int i=0;i<8;i++)
    {
        if(i==s) continue;
        auto [a,b,c] = v[i];
        w.push_back((x-a)*(x-a)+(y-b)*(y-b)+(z-c)*(z-c));
    }
    sort(w.begin(), w.end());
    if(w[0]==w[1]&&w[1]==w[2]&&w[3]==w[4]&&w[4]==w[5])
    {
        if(w[3]==w[0]+w[0])
        {
            if(w[0]+w[3]==w[6])
            {
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        v.clear();
        for(int i=0;i<8;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            v.emplace_back(x,y,z);
        }
        sort(v.begin(), v.end());
        if(unique(v.begin(),v.end())!=v.end())
        {
            cout<<"NO"<<'\n';
            continue;
        }
        bool flag = true;
        for(int i=0;i<8;i++)
            if(!f(i)) flag = false;
        cout<<(flag?"YES":"NO")<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
