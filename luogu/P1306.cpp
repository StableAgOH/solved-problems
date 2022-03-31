#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <cstring>
#include <algorithm>
const int mod = 1e8;
typedef long long ll;
struct Matrix
{
    int r,c;
    ll ele[2][2];
    Matrix(int r,int c) : r(r),c(c) { memset(ele, 0, sizeof(ele)); }
};
Matrix operator*(Matrix& A, Matrix& B)
{
    Matrix C(A.r, B.c);
    for(int i=0;i<A.r;i++)
        for(int j=0;j<B.c;j++)
            for(int k=0;k<A.c;k++)
                C.ele[i][j]=(C.ele[i][j]+A.ele[i][k]*B.ele[k][j]%mod)%mod;
    return C;
}
Matrix qpow(Matrix A, ll k)
{
    Matrix R = A;
    for(k--;k;k>>=1,A=A*A)
        if(k&1)
            R=R*A;
    return R;
}
ll fib(int n)
{
    if(n<=2) return 1;
    else 
    {
        Matrix A(2,2);
        A.ele[0][1]=A.ele[1][0]=A.ele[1][1]=1;
        Matrix B(2,1);
        B.ele[0][0]=B.ele[1][0]=1;
        Matrix T = qpow(A, n-2);
        Matrix C = T * B;
        return C.ele[1][0];
    }
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
    int n,m;
    cin>>n>>m;
    cout<<fib(__gcd(n,m))<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
