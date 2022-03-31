#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
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
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int t1=0,t2=0;
    for(int i=0;i<s1.size();i+=2)
    {
        if(s1[i]=='8')
        {
            if(s2[i]=='(') t2++;
            else if(s2[i]=='[') t1++;
        }
        else if(s1[i]=='(')
        {
            if(s2[i]=='8') t1++;
            else if(s2[i]=='[') t2++;
        }
        else
        {
            if(s2[i]=='8') t2++;
            else if(s2[i]=='(') t1++;
        }
    }
    if(t1>t2) cout<<"TEAM 1 WINS"<<endl;
    else if(t2>t1) cout<<"TEAM 2 WINS"<<endl;
    else cout<<"TIE"<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
