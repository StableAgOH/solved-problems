#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <list>
#include <algorithm>
int len(int x)
{
    int cnt = 0;
    while(x)
    {
        x /= 10;
        cnt++;
    }
    return cnt;
}
void clean(list<int>& a, list<int>& b)
{
    a.sort();
    b.sort();
    auto it1=a.begin(), it2=b.begin();
    while(it1!=a.end()&&it2!=b.end())
    {
        if(*it1<*it2) ++it1;
        else if(*it2<*it1) ++it2;
        else
        {
            a.erase(it1++);
            b.erase(it2++);
        }
    }
}
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
        int n;
        cin>>n;
        list<int> a, b;
        for(int i=0;i<n;i++) { int x; cin>>x; a.push_back(x); }
        for(int i=0;i<n;i++) { int x; cin>>x; b.push_back(x); }
        int cnt = 0;
        clean(a, b);
        for(auto& i : a) if(i>=10) i=len(i), cnt++;
        for(auto& i : b) if(i>=10) i=len(i), cnt++;
        clean(a, b);
        for(auto& i : a) if(i>1) cnt++;
        for(auto& i : b) if(i>1) cnt++;
        cout<<cnt<<endl;
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
