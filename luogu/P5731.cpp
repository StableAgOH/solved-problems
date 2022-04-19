#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
//==========================================
const int MAXN = 11;
int a[MAXN][MAXN];
enum Dir { UP,DOWN,LEFT,RIGHT };
Dir change(Dir d)
{
    switch(d)
    {
    case UP: return RIGHT;
    case RIGHT: return DOWN;
    case DOWN: return LEFT;
    case LEFT: return UP;
    }
}
int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    clock_t c1 = clock();
    //======================================
    int n,cnt=1;
    cin>>n;
    Dir d = RIGHT;
    int x=1,y=1;
    while(true)
    {
        a[x][y] = cnt++;
        if((a[x-1][y]||x==1)&&(a[x+1][y]||x==n)&&(a[x][y-1]||y==1)&&(a[x][y+1]||y==n))
            break;
        if( ((x==n||a[x+1][y])&&d==RIGHT) ||\
            ((y==n||a[x][y+1])&&d==DOWN ) ||\
            ((x==1||a[x-1][y])&&d==LEFT ) ||\
            ((y==1||a[x][y-1])&&d==UP   )   \
        ) d = change(d);
        switch(d)
        {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j][i]<10) cout<<"  "<<a[j][i];
            else cout<<' '<<a[j][i];
        }
        cout<<endl;
    }
    //======================================
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}