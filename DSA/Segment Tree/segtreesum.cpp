//Sum and Update queries
#include <bits/stdc++.h>
using namespace std;

void build(int arr[], int tree[], int v, int tl, int tr)
{
    if (tl == tr)
        tree[v] = arr[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(arr, tree, 2 * v, tl, tm);
        build(arr, tree, 2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

int sum(int tree[], int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return tree[v];
    }
    else
    {
        int tm = (tr + tl) / 2;
        return sum(tree, 2 * v, tl, tm, l, min(r, tm)) + sum(tree, 2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    }
}

//arr[i] = val updated
void update(int tree[], int v, int tl, int tr, int pos, int val)
{
    if (tl == tr)
    {
        tree[v] = val;
    }
    else
    {
        int tm = (tr + tl) / 2;
        if (pos <= tm)
            update(tree, 2 * v, tl, tm, pos, val);
        else
            update(tree, 2 * v + 1, tm + 1, tr, pos, val);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

int main()
{
    int arr[] = {3, -1, 2, 7, -8};
    int n = 5;
    int tree[4 * n];
    build(arr, tree, 1, 0, n - 1);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum(tree, 1, 0, n - 1, l, r) << endl;
    }
    return 0;
}
