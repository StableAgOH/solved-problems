#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <string>
struct student
{
    string name;
    int sc1, sc2;
    bool b1, b2;
    int cnt;
    friend istream& operator>>(istream& is, student& s)
    {
        is>>s.name>>s.sc1>>s.sc2;
        char c1, c2;
        is>>c1>>c2;
        s.b1 = c1=='Y'?true:false;
        s.b2 = c2=='Y'?true:false;
        is>>s.cnt;
        return is;
    }
    friend ostream& operator<<(ostream& os, student& s)
    {
        os<<s.name<<'\n';
        return os;
    }
};
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    int mx = 0;
    int sum = 0;
    student ans;
    for(int i=0;i<n;i++)
    {
        student stu;
        cin>>stu;
        int tot = 0;
        if(stu.sc1>80&&stu.cnt>0) tot+=8000;
        if(stu.sc1>85&&stu.sc2>80) tot+=4000;
        if(stu.sc1>90) tot+=2000;
        if(stu.sc1>85&&stu.b2) tot+=1000;
        if(stu.sc2>80&&stu.b1) tot+=850;
        if(tot>mx) ans = stu, mx = tot;
        sum += tot;
    }
    cout<<ans<<mx<<endl<<sum<<endl;
    //======================================
#ifdef LOCAL
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}