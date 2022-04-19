#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
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
    vector<int> v;
    for(int i=0;i<3;i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int a = v[0], b = v[1], c = v[2];
    if(a+b<=c) cout<<"Not triangle"<<endl;
    else
    {
        if(a*a+b*b==c*c) cout<<"Right triangle"<<endl;
        else if(a*a+b*b>c*c) cout<<"Acute triangle"<<endl;
        else cout<<"Obtuse triangle"<<endl;
        if(a==b||b==c||a==c) cout<<"Isosceles triangle"<<endl;
        if(a==b&&a==c&&b==c) cout<<"Equilateral triangle"<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
