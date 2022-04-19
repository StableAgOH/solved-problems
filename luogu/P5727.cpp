#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <stack>
stack<int> st;
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
    while(n!=1)
    {
        st.push(n);
        if(n%2) n = n*3+1;
        else n >>= 1;
    }
    cout<<1<<' ';
    while(st.size())
    {
        cout<<st.top()<<' ';
        st.pop();
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
