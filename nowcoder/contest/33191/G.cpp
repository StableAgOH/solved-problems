#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
#include <vector>
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
    cout<<string(13*n+19,'*')<<endl;
    const string l = '*'+string(13*n+17,'.')+'*';
    for(int j=1;j<=n;j++) cout<<l<<endl;
    vector<string> v;
    v.resize(2*n+3, l);
    // N
    for(int j=0;j<2*n+3;j++) v[j][n+2] = '@';
    for(int j=0;j<2*n+3;j++) v[j][3*n+4] = '@';
    for(int j=0,k=n+2;j<2*n+3;j++,k++) v[j][k] = '@';
    // F
    for(int j=0;j<2*n+3;j++) v[j][4*n+6] = '@';
    for(int j=4*n+6;j<6*n+9;j++) v[0][j] = '@';
    for(int j=4*n+6;j<6*n+9;j++) v[n+1][j] = '@';
    // L
    for(int j=0;j<2*n+3;j++) v[j][7*n+10] = '@';
    for(int j=7*n+10;j<9*n+13;j++) v[2*n+2][j] = '@';
    // S
    for(int j=10*n+14;j<12*n+17;j++) v[0][j] = '@';
    for(int j=10*n+14;j<12*n+17;j++) v[n+1][j] = '@';
    for(int j=10*n+14;j<12*n+17;j++) v[2*n+2][j] = '@';
    for(int j=0;j<n+2;j++) v[j][10*n+14] = '@';
    for(int j=n+2;j<2*n+3;j++) v[j][12*n+16] = '@';

    for(auto&& s : v) cout<<s<<endl;
    for(int j=1;j<=n;j++) cout<<l<<endl;
    cout<<string(13*n+19,'*')<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
