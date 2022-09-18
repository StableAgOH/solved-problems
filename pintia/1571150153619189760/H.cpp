#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <stack>
#include <vector>
#include <string>
const int mod = 20220911;
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
    vector<string> v;
    string s;
    while(cin>>s) v.emplace_back(s);
    stack<ll> st;
    st.push(0);
    for(size_t i=0;i<v.size();i++)
    {
        if(v[i]=="library") st.top()++;
        else if(v[i]=="repeat") st.push(0);
        else if(v[i]=="for")
        {
            ll x = stoi(v[i+1]);
            ll y = st.top();
            st.pop();
            st.top() = (st.top()+x*y)%mod;
            i += 2;
        }
    }
    cout<<st.top()<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
