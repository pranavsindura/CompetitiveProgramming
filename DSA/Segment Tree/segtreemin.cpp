#include<bits/stdc++.h>
using namespace std;
int tree[400005];
int arr[100005];
void build(int tree[], int arr[], int v, int tl, int tr)
{
    if(tl==tr)
    {
        tree[v] = arr[tl];
    }
    else
    {
        int tm = (tl+tr)/2;
        build(tree, arr, 2*v, tl, tm);
        build(tree, arr, 2*v+1, tm+1, tr);
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}
 
int lrmin(int tree[], int v, int tl, int tr, int l, int r)
{
    if(l>r)
    {
        return INT_MAX;
    }
    if(tl == l && tr == r)
    {
        return tree[v];
    }
    else
    {
        int tm=(tl+tr)/2;
        return min(lrmin(tree,2*v, tl, tm, l, min(tm, r)), lrmin(tree, 2*v+1, tm+1, tr, max(l,tm+1),r));
    }
}

void update(int tree[], int v, int tl, int tr, int pos, int val)
{
    if(tl == tr)
    {
        tree[v] = val;
    }
    else
    {
        int tm=(tl+tr)/2;
        if(pos<=tm)
        {
            update(tree, 2*v, tl, tm, pos, val);
        }
        else
        {
            update(tree, 2*v+1,tm+1, tr, pos, val);
        }
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}

int main()
{
    int n, t;
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build(tree, arr, 1, 0, n-1);
    while(t--)
    {
        char q;
        int x,y;
        cin>>q>>x>>y;
        if(q=='q')
        {
            cout<<lrmin(tree, 1, 0, n-1, x-1, y-1)<<endl;
        }
        else
        {
            arr[x-1] = y;
            update(tree, 1, 0, n-1, x-1, y);
        }
    }
    return 0;
}
