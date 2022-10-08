#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
map<int, multiset<int>> s, r;
void input(map<int, multiset<int>>& s, int n)
{
    for(int i=0;i<n;i++)
    {
        int id,k;
        cin>>id>>k;
        for(int j=0;j<k;j++)
        {
            int x;
            cin>>x;
            s[id].insert(x);
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
    int n,m;
    cin>>n>>m;
    input(s, n);
    input(r, m);
    int a=0, b=0, c=0;
    auto it1=s.begin(), it2=r.begin();
    while(it1!=s.end()&&it2!=r.end())
    {
        auto& [id1, s1] = *it1;
        auto& [id2, s2] = *it2;
        if(id1<id2)
        {
            a++;
            c += s1.size();
            cout<<id1<<' ';
            for(auto j : s1) cout<<'+'<<j<<' ';
            cout<<'\n';
            ++it1;
        }
        else if(id2<id1)
        {
            a++;
            b += s2.size();
            cout<<id2<<' ';
            for(auto j : s2) cout<<'-'<<j<<' ';
            cout<<'\n';
            ++it2;
        }
        else
        {
            vector<int> v, w;
            set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(v, v.end()));
            set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), inserter(w, w.end()));
            b += w.size();
            c += v.size();
            for(auto j : w) v.push_back(-j);
            sort(v.begin(), v.end(), [](int x,int y) { return abs(x)<abs(y); });
            if(!v.empty())
            {
                a++;
                cout<<id1<<' ';
                for(auto j : v)
                {
                    if(j>0) cout<<'+';
                    cout<<j<<' ';
                }
                cout<<'\n';
            }
            ++it1;
            ++it2;
        }
    }
    while(it1!=s.end())
    {
        auto& [id1, s1] = *it1;
        a++;
        c += s1.size();
        cout<<id1<<' ';
        for(auto j : s1) cout<<'+'<<j<<' ';
        cout<<'\n';
        ++it1;
    }
    while(it2!=r.end())
    {
        auto& [id2, s2] = *it2;
        a++;
        b += s2.size();
        cout<<id2<<' ';
        for(auto j : s2) cout<<'-'<<j<<' ';
        cout<<'\n';
        ++it2;
    }
    if(!a) cout<<"GREAT WORK! NO MISTAKES FOUND!"<<'\n';
    else cout<<"MISTAKES IN "<<a<<" STUDENTS: "<<b<<" NOT REQUESTED, "<<c<<" MISSED"<<'\n';
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
