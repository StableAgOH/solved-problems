#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <iterator>
#include <algorithm>
const string one = "adgjmptw";
const string two = "behknqux";
const string thr = "cfilorvy";
const string fou = "sz";
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
    string s;
    getline(cin, s);
    int sum = 0;
    for_each(s.begin(), s.end(), [&sum](char c) {
        if(c==' ') sum++;
        else 
        {
            for(int i=0;i<8;i++)
            {
                if(c==one[i])
                {
                    sum++;
                    break;
                }
                else if(c==two[i])
                {
                    sum += 2;
                    break;
                }
                else if(c==thr[i])
                {
                    sum += 3;
                    break;
                }
                else if(c==fou[i])
                {
                    sum += 4;
                    break;
                }
            }
        }
    });
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
