#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
int calc(const string& s)
{
    int sum = 0;
    for(int i=0;i<s.length()-1;i++)
        sum += stoi(s.substr(i,2));
    return sum;
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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int l=0, r=s.length()-1;
        for(;l<s.length();l++) if(s[l]=='1') break;
        if(l==s.length())
        {
            cout<<0<<'\n';
            continue;
        }
        for(;r>=0;r--) if(s[r]=='1') break;
        size_t mn = min((size_t)l, s.length()-r-1);
        size_t mx = max((size_t)l, s.length()-r-1);
        if(k>=mn&&k<mx)
        {
            if(l<s.length()-r-1) swap(s[0], s[l]);
            else swap(s[n-1], s[r]);
        }
        else if(k>=mx&&k<mn+mx)
        {
            swap(s[n-1], s[r]);
        }
        else if(k>=mn+mx)
        {
            swap(s[n-1], s[r]);
            if(l!=r) swap(s[0], s[l]);
        }
        cout<<calc(s)<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
