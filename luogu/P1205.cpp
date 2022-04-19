#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <algorithm>
int n;
string tmp;
vector<string> s1, s2, s3;
void rotate()
{
    s3.clear();
    for(int i=0;i<n;i++)
    {
        tmp.clear();
        for(int j=n-1;j>=0;j--)
            tmp.push_back(s1[j][i]);
        s3.push_back(tmp);
    }
    copy(s3.begin(), s3.end(), s1.begin());
}
void flip()
{
    for_each(s1.begin(), s1.end(), [](auto& s) { reverse(s.begin(), s.end()); });
}
bool judge()
{
    for(int i=0;i<n;i++)
        if(s1[i]!=s2[i])
            return false;
    return true;
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
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        s1.push_back(tmp);
    }
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        s2.push_back(tmp);
    }
    if(rotate(), judge()) cout<<1<<endl;
    else if(rotate(), judge()) cout<<2<<endl;
    else if(rotate(), judge()) cout<<3<<endl;
    else if(rotate(), flip(), judge()) cout<<4<<endl;
    else
    {
        for(int i=0;i<3;i++)
        {
            if(rotate(), judge())
            {
                cout<<5<<endl;
                goto end;
            }
        }
        cout<<7<<endl;
    }
    end:
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
