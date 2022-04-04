#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <map>
#include <queue>
const int maxn = 1e5+5;
int a[maxn];
int n,k;
bool judge(int x)
{
    map<int,int> mp;
    map<int,int> pm;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int tmp = pm[a[i]];
        if(tmp)
        {
            cnt++;
            mp.erase(mp.find(tmp));
            pm[a[i]]=i;
            mp[i]=a[i];
        }
        else
        {
            if(mp.size()==x)
            {
                pm[(*mp.begin()).second]=0;
                mp.erase(mp.begin());
            }
            mp[i]=a[i];
            pm[a[i]]=i;
        }
    }
    return cnt>=k;
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    cin>>n>>k;
    map<int,int> mp;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!mp[a[i]]) mp[a[i]]++;
        else cnt++;
    }
    if(cnt<k) cout<<"cbddl"<<endl;
    else
    {
        int l=1, r=n;
        while(l<r)
        {
            int m=(l+r)>>1;
            if(judge(m)) r=m;
            else l=m+1;
        }
        cout<<l<<endl;
    }
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
