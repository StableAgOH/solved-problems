#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
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
    int n,k;
    cin>>n>>k;
    int cnt = 0;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(!v.empty()&&(v.back()==x||v.back()+x==k))
        {
            v.pop_back();
            cnt++;
        }
        else v.push_back(x);
    }
    int l=0, r=v.size()-1;
    while(l<r&&(v[l]==v[r]||v[l]+v[r]==k)) cnt++,l++,r--;
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
