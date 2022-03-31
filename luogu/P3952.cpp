#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
#include <regex>
#include <numeric>
#include <cstring>
const int maxn = 105;
int a[maxn];
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
    string s;
    getline(cin, s);
    smatch mr;
    while(t--)
    {
        getline(cin, s);
        regex_match(s, mr, regex("(\\d+) O\\((?:1|(?:n\\^(\\d+)))\\)"));
        int n = stoi(mr[1].str()), k = mr[2].matched?stoi(mr[2].str()):0;
        string vars;
        bool flag = false;
        int cnt = 0, skip = -1, mx = -1;
        memset(a, 0, sizeof(a));
        for(int i=1;i<=n;i++)
        {
            getline(cin, s);
            if(cnt<0) flag=true;
            else if(!cnt)
            {
                mx = max(mx, accumulate(a,a+maxn,0));
                memset(a, 0, sizeof(a));
            }
            if(flag) continue;
            if(regex_match(s, mr, regex("F ([a-z]) (n|\\d+) (n|\\d+)")))
            {
                cnt++;
                char var = mr[1].str()[0];
                if(vars.find(var)!=string::npos)
                {
                    flag = true;
                    continue;
                }
                vars.push_back(var);
                if(skip!=-1&&cnt>skip) continue;
                int bg = mr[2].str()=="n"?-1:stoi(mr[2].str());
                int ed = mr[3].str()=="n"?-1:stoi(mr[3].str());
                if((ed!=-1&&(bg>ed||bg==-1))) skip=cnt;
                else if(bg!=-1&&ed==-1) a[cnt]=1;
            }
            else
            {
                vars.pop_back();
                if(cnt--==skip) skip=-1;
            }
        }
        mx = max(mx, accumulate(a,a+maxn,0));
        if(flag||vars.length()) cout<<"ERR"<<endl;
        else if(mx==k) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}