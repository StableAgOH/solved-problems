#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <vector>
#include <algorithm>
const string sa[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
const string s1[] = {"a", "another", "first"};
const string s2[] = {"both", "second"};
const string s3 = "third";
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
    string s[6];
    vector<int> v;
    for(int i=0;i<6;i++) 
    {
        cin>>s[i];
        for(int j=0;j<20;j++)
        {
            if(s[i]==sa[j]) v.push_back(j+1);
            else if(s[i]==s1[0]||s[i]==s1[1]||s[i]==s1[2])
            {
                v.push_back(1);
                break;
            }
            else if(s[i]==s2[0]||s[i]==s2[1])
            {
                v.push_back(2);
                break;
            }
            else if(s[i]==s3)
            {
                v.push_back(3);
                break;
            }
        }
    }
    sort(v.begin(), v.end());
    int tmp;
    long long sum = 0;
    for(int i=0;i<v.size();i++)
    {
        tmp = v[i]*v[i]%100;
        v[i] = tmp;
    }
    for(auto i : v)
    {
        sum *= 100;
        sum += i;
    }
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
