#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <vector>
typedef pair<int,int> pii;
vector<pii> v11,v21;
void judge11()
{
    int x=v11.back().first, y=v11.back().second;
    if(abs(x-y)>1&&(x>=11||y>=11)) v11.emplace_back(0,0);
}
void judge21()
{
    int x=v21.back().first, y=v21.back().second;
    if(abs(x-y)>1&&(x>=21||y>=21)) v21.emplace_back(0,0);
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
    string s,tmp;
    while(getline(cin,tmp)) s += tmp;
    v11.emplace_back(0,0);
    v21.emplace_back(0,0);
    bool flag = false;
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if(c=='E')
        {
            if(i!=s.length()-1&&s[i+1]=='a')flag = true;
            break;
        }
        if(c=='W')
        {
            v11.back().first+=1;
            v21.back().first+=1;
            judge11(), judge21();
        }
        else if(c=='L')
        {
            v11.back().second+=1;
            v21.back().second+=1;
            judge11(), judge21();
        }
    }
    for(auto i : v11)
        if(v11.size()==1 || (v11.size()>1&&i!=pii(0,0)))
            cout<<i.first<<':'<<i.second<<endl;
    if(flag) cout<<"0:0"<<endl;
    cout<<endl;
    for(auto i : v21) 
        if(v11.size()==1 || (v11.size()>1&&i!=pii(0,0)))
            cout<<i.first<<':'<<i.second<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
