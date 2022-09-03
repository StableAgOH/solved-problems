#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <stack>
#include <functional>
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
    int n;
    cin>>n;
    cin.get();
    string s(n+1, '\0');
    for(int i=1;i<=n;i++) s[i] = cin.get();
    vector<int> rt(n+1);
    stack<int> st;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(') st.push(i);
        else if(s[i]==')')
        {
            int t = st.top();
            st.pop();
            rt[t] = i;
        }
    }
    function<void(int,int)> f = [&](int l,int r) {
        for(int i=l+1;i<=r;i++)
        {
            if(s[i]=='(')
            {
                f(i, rt[i]);
                cout<<i<<' ';
                i = rt[i];
            }
            else cout<<i<<' ';
        }
    };
    f(0, n);
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
