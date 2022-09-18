#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <set>
set<int> st;
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
    st.insert(2);
    for(int i=2;i<=15;i++)
    {
        for(int j=(1<<(i-1))-1,x,y;j<(1<<(29-i));x=j&-j,y=j+x,j=((j&~y)/x>>1)|y)
        {
            int z = (j<<(i+1))+(1<<i);
            if(z>1e9) continue;
            st.insert(z);
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        auto it = st.lower_bound(l);
        if(it!=st.end()&&*it<=r) cout<<*it<<'\n';
        else cout<<-1<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
