#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
const int maxn = 1e5+5;
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
    string s;
    while(getline(cin, s))
    {
        stringstream ss(s);
        string t,p;
        ss>>t>>p;
        int sec;
        if(count(t.begin(),t.end(),':')==1)
        {
            int p = t.find(':');
            sec = stoi(t.substr(0,p))*60+stoi(t.substr(p+1));
        }
        else 
        {
            int p1 = t.find(':');
            int p2 = t.find(':', p1+1);
            sec = stoi(t.substr(0,p1))*60*60+stoi(t.substr(p1+1,p2))*60+stoi(t.substr(p2+1));
        }
        double spd = stof(p.substr(0, p.length()-1));
        sec = round(sec/spd);
        if(sec>=3600)
        {
            int a = sec/3600;
            int b = (sec-3600*a)/60;
            int c = sec%60;
            cout<<a<<':';
            if(b<10) cout<<0;
            cout<<b<<':';
            if(c<10) cout<<0;
            cout<<c<<'\n';
        }
        else
        {
            int a = sec/60;
            int b = sec%60;
            cout<<a<<':';
            if(b<10) cout<<0;
            cout<<b<<'\n';
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
