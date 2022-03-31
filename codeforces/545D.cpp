#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    static std::vector<int> v;
    int n;
    cin>>n;
    int tmp;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        v.push_back(tmp);
    }
    std::sort(v.begin(),v.end());
    int ans=0,tim=0;
    for(auto i : v)
    {
        if(tim>i) continue;
        ans++;
        tim+=i;
    }
    cout<<ans<<endl;
    return 0;
}