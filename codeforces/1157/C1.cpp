#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
#include <deque>
#include <string>
deque<int> dq;
string s;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        dq.push_back(x);
    }
    int last=-1;
    while(!dq.empty())
    {
        int f=dq.front(), b=dq.back();
        if(f>last&&b>last)
        {
            if(f<b)
            {
                dq.pop_front();
                s.push_back('L');
                last=f;
            }
            else
            {
                dq.pop_back();
                s.push_back('R');
                last=b;
            }
        }
        else if(f>last)
        {
            dq.pop_front();
            s.push_back('L');
            last=f;
        }
        else if(b>last)
        {
            dq.pop_back();
            s.push_back('R');
            last=b;
        }
        else break;
    }
    cout<<s.length()<<endl<<s<<endl;
    //======================================
    exit();
}