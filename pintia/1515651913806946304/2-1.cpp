#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
stack<int> st;
unordered_map<string, int> mp;
int main()
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n,k;
    cin>>n>>k;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    for(int i=0;i<n/k;i++)
    {
        for(int j=0;j<k;j++)
        {
            int x;
            cin>>x;
            st.push(x);
        }
        for(int j=0;j<k;j++)
        {
            mp[v[i*k+j]] = st.top();
            st.pop();
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        if(mp.find(s)==mp.end()) cout<<"Wrong Number"<<endl;
        else cout<<mp[s]<<endl;
    }
    return 0;
}
