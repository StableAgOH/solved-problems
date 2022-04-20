#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <algorithm>
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
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='-'&&i!=0&&i!=s.length()-1&&(islower(s[i-1])&&islower(s[i+1])||isdigit(s[i-1])&&isdigit(s[i+1]))&&s[i+1]-s[i-1]>=1)
        {
            string t;
            for(char c=s[i-1]+1;c!=s[i+1];c++)
            {
                if(p1==1&&islower(c)) t.append(string(p2, c));
                else if(p1==2&&islower(c)) t.append(string(p2, toupper(c)));
                else if(p1==3) t.append(string(p2, '*'));
                else t.append(string(p2, c));
            }
            if(p3==2) reverse(t.begin(), t.end());
            cout<<t;
        }
        else cout<<s[i];
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
