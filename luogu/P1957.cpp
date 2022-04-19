#include <iostream>
#include <chrono>
using namespace std;
//==========================================
char f(int opt)
{
    switch(opt)
    {
    case 1: return '+';
    case 2: return '-';
    case 3: return '*';
    }
}
int g(int opt,int x,int y)
{
    switch(opt)
    {
    case 1: return x+y;
    case 2: return x-y;
    case 3: return x*y;
    }
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y,opt;
        string s;
        cin>>s;
        if(isdigit(s[0]))
        {
            x = stoi(s);
            cin>>y;
        }
        else
        {
            switch(s[0])
            {
            case 'a':
                opt = 1;
                break;
            case 'b':
                opt = 2;
                break;
            case 'c':
                opt = 3;
                break;
            }
            cin>>x>>y;
        }
        s = to_string(x);
        s.push_back(f(opt));
        s.append(to_string(y));
        s.push_back('=');
        s.append(to_string(g(opt,x,y)));
        cout<<s<<endl<<s.size()<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
