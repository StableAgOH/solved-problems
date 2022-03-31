#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <stack>
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    stack<int> st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        if(st.empty()||st.top()==tmp)
            st.push(tmp);
        if(st.top()!=tmp) st.pop();
    }
    cout<<st.top()<<endl;
    //======================================
#ifdef LOCAL
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}