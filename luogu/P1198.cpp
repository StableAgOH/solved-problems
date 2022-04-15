#include <iostream>
#include <ctime>
#include <cstdio>
#include <climits>
#include <functional>
template <typename _Tp, typename _Opr = std::plus<_Tp>>
class SegmentTree
{

private:
    struct Node
    {
        int l, r;
        Node *ls, *rs;
        _Tp data;
    } * Head;
    _Tp *p;
    void build(Node *Pointer, const int l, const int r)
    {
        Pointer->l = l, Pointer->r = r;
        if (l == r)
        {
            Pointer->data = *p++;
            Pointer->ls = Pointer->rs = nullptr;
            return;
        }
        Pointer->ls = new Node, Pointer->rs = new Node;
        int mid = (l + r) / 2;
        build(Pointer->ls, l, mid);
        build(Pointer->rs, mid + 1, r);
        Pointer->data = Opr(Pointer->ls->data, Pointer->rs->data);
    }
    _Tp ask(Node *Pointer, const int x)
    {
        if (Pointer->l == Pointer->r)
            return Pointer->data;
        if (x <= (Pointer->l + Pointer->r) / 2)
            return ask(Pointer->ls, x);
        else
            return ask(Pointer->rs, x);
    }
    _Tp ask(Node *Pointer, const int l, const int r)
    {
        if (Pointer->l >= l && Pointer->r <= r)
            return Pointer->data;
        int mid = (Pointer->l + Pointer->r) / 2;
        _Tp ans = INT_MIN;
        if (l <= mid)
            ans = Opr(ans, ask(Pointer->ls, l, r));
        if (r > mid)
            ans = Opr(ans, ask(Pointer->rs, l, r));
        return ans;
    }
    void modify(Node *Pointer, const int x, const int k)
    {
        if (Pointer->l == Pointer->r)
        {
            Pointer->data = Opr(Pointer->data, k);
            return;
        }
        int mid = (Pointer->l + Pointer->r) / 2;
        if (x <= mid)
            modify(Pointer->ls, x, k);
        else
            modify(Pointer->rs, x, k);
        Pointer->data = Opr(Pointer->ls->data, Pointer->rs->data);
    }

protected:
    _Opr Opr;

public:
    SegmentTree(_Tp *add, const int size)
    {
        p = add;
        Head = new Node;
        build(Head, 1, size);
    }
    _Tp Query(const int x) { return ask(Head, x); }
    _Tp Query(const int l, const int r) { return ask(Head, l, r); }
    void Modify(const int x, const _Tp k) { modify(Head, x, k); }
    void Print()
    {
        for (int i = 1; i <= Head->r; i++)
            std::cout << Query(i) << ' ';
    }
};
//======================================
int a[200000];
template <typename T>
struct maxium
{
    T operator()(T a, T b) const { return a > b ? a : b; }
};
SegmentTree<int, maxium<int>> st(a, 200000);
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    clock_t c1 = clock();
    //======================================
    int n, mod, tmp, t = 0, size = 0;
    char opt;
    scanf("%d%d", &n, &mod);
    while (n--)
    {
        std::cin >> opt;
        if (opt == 'Q')
        {
            scanf("%d", &tmp);
            printf("%d\n", t = st.Query(size - tmp + 1, size + 1));
        }
        else
        {
            scanf("%d", &tmp);
            st.Modify((size++) + 1, (t % mod + tmp) % mod);
        }
    }
    //======================================
    std::cerr << clock() - c1 << std::endl;
    return 0;
}