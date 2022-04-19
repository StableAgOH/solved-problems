#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <cmath>
const int maxn = 1005;
struct S
{
    int a,b,c;
}stu[maxn];
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
    int n;
    cin>>n;
    int cnt = 0;
    for(int i=0;i<n;i++) cin>>stu[i].a>>stu[i].b>>stu[i].c;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int tmp1 = abs(stu[i].a-stu[j].a);
            int tmp2 = abs(stu[i].b-stu[j].b);
            int tmp3 = abs(stu[i].c-stu[j].c);
            int tmp4 = abs(stu[i].a+stu[i].b+stu[i].c-stu[j].a-stu[j].b-stu[j].c);
            if(tmp1<=5&&tmp2<=5&&tmp3<=5&&tmp4<=10) cnt++;
        }
    }
    cout<<cnt<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
