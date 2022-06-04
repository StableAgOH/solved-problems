#include <iostream>
#include <ctime>
using namespace std;
//==========================================
#include <stack>
const int maxn = 1e5 + 5;
int a[maxn];
bool dp[maxn][10];
int pre[maxn][10];
stack<int> st;
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
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<=5;i++)
        dp[0][i]=true;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(!dp[i][j]) continue;
            if(a[i+1]<a[i])
            {
                for(int k=j-1;k>=1;k--)
                {
                    dp[i+1][k]=true;
                    pre[i+1][k]=j;
                }
            }
            else if(a[i+1]>a[i])
            {
                for(int k=j+1;k<=5;k++)
                {
                    dp[i+1][k]=true;
                    pre[i+1][k]=j;
                }
            }
            else for(int k=1;k<=5;k++)
            {
                if(k==j) continue;
                dp[i+1][k]=true;
                pre[i+1][k]=j;
            }
        }
    }
    for(int i=1;i<=5;i++)
    {
        if(dp[n-1][i])
        {
            st.push(i);
            int tmp = i;
            for(int j=n-1;j>0;j--)
            {
                st.push(pre[j][tmp]);
                tmp = pre[j][tmp];
            }
            while(!st.empty())
            {
                cout<<st.top()<<' ';
                st.pop();
            }
            goto end;
        }
    }
    cout<<-1<<endl;
    //======================================
end:
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}