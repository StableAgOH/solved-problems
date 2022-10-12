#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <functional>
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        function<int(int,int)> msort = [&](int l,int r) {
            int cnt = 0;
            if(l<r)
            {
                int m = (l+r)>>1;
                cnt += msort(l, m);
                cnt += msort(m+1, r);
                if(v[l]>v[m+1])
                {
                    cnt++;
                    int p=l, q=m+1;
                    while(p<=m)
                    {
                        swap(v[p], v[q]);
                        p++; q++;
                    }
                }
            }
            return cnt;
        };
        int x = msort(1,n);
        if(is_sorted(v.begin()+1, v.end())) cout<<x<<'\n';
        else cout<<-1<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
