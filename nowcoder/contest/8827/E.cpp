// By Zxilly
#include <bits/stdc++.h>

using namespace std;

// short pre[100001];

map<int, int> temp;

int inputArray[1000005] = {0};

int main()
{
    temp[0] = 1;
    // memset(pre, 0, sizeof(pre));
    int n, tmp = 0, now = 0;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inputArray[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int swap = inputArray[i];
        now ^= (1 << swap);
        ans += temp[now];
        temp[now] += 1;
        /* code */
    }

    printf("%lld", ans);

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &tmp);
    //     if (i != 0)
    //     {
    //         for (int j=0;j<20;j++){
    //             pre[i][j]=pre[i-1][j];
    //         }
    //     }
    //     pre[i][tmp]++;
    // }
}