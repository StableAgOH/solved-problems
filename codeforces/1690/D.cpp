#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <vector>
const int maxn = 1e5+5;
typedef long long ll;
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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> v(n);
        int b=0, w=0;
        for(int i=0;i<k;i++)
        {
            if(s[i]=='B') b++;
            else w++;
        }
        v[k-1] = w;
        for(int i=k;i<n;i++)
        {
            if(s[i-k]=='B') b--;
            else w--;
            if(s[i]=='B') b++;
            else w++;
            v[i] = w;
        }
        cout<<*min_element(v.begin()+k-1, v.end())<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
