#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pdd = pair<double,double>;
double sqare(double x) { return x*x; }
double distance(const pdd& p1, const pdd& p2)
{
    return sqrt(sqare(p1.first-p2.first)+sqare(p1.second-p2.second));
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        vector<vector<pdd>> a(2, vector<pdd>(2));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                cin>>a[i][j].first>>a[i][j].second;
        vector<pdd> c(2);
        for(int i=0;i<2;i++) c[i] = {(a[i][0].first+a[i][1].first)/2.0, (a[i][0].second+a[i][1].second)/2.0};
        double r = distance(a[1][0], a[1][1])/2;
        double e = r*sqrt(2)/2;
        double x1=c[1].first, y1=c[1].second;
        if(c[1].first>c[0].first) x1 -= e;
        else x1 += e;
        if(c[1].second>c[0].second) y1 -= e;
        else y1 += e;
        cout<<fixed<<setprecision(10)<<fabs(x1-c[0].first)+fabs(y1-c[0].second)<<'\n';
    }
    return 0;
}
