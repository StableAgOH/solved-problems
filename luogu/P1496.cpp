#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <algorithm>
const int maxn = 2e4+5;
int a[maxn], b[maxn];
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    sort(a, a+n);
    sort(b, b+n);
    long long sum = b[0]-a[0];
    for(int i=1;i<n;i++) sum += b[i]-max(a[i], b[i-1]);
    cout<<sum<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
