#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
const int maxn = 1e5+5;
typedef long long ll;
bool judge(const string& a, const string& b)
{
    if(count(a.begin(), a.end(), 'b')!=count(b.begin(), b.end(), 'b')) return false;
    size_t j = -1;
    for(size_t i=0;i<a.length();i++)
    {
        char c = a[i];
        if(c=='b') continue;
        j = b.find(c, j+1);
        if(j==string::npos) return false;
        if(c=='a'&&j<i) return false;
        if(c=='c'&&j>i) return false;
    }
    return true;
}
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        cout<<(judge(a,b)?"YES":"NO")<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
