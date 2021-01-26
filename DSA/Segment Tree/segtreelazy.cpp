#include <bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
struct data{
    int max; 
    int min;
};
#define data struct data
data tree[400005];
int lazy[100005];
// bool marked[100005];
data combine(data n1, data n2)
{
    data n;
    n.max = max(n1.max, n2.max);
    n.min = min(n1.min, n2.min);
}
void query(int arr[], int v, int x, int tl, int tr, int prevpen)
{
    tree[v].max -=prevpen;
    tree[v].min -=prevpen;
    lazy[v] += prevpen;
    if(x >= tree[v].max)
    {
        if(tl == tr)
        {
            lazy[v] = 0;
        }
        return;
    }
    if(x < tree[v].max)
    {
        if(x < tree[v].min)
        {
            lazy[v]++;
            tree[v].max--;
            tree[v].min--;
            if(tl == tr)
            {
                lazy[v] = 0;
            }
            return;
        }
        else
        {
            tree[v].max--;
            int tm = (tl+tr)/2;
            query(arr, 2*v, x, tl, tm, lazy[v]);
            query(arr, 2*v+1, x, tm+1, tr, lazy[v]);
            lazy[v] = 0;
        }
    }
}
void build(int arr[], int v, int tl, int tr)
{
    if(tl == tr)
    {
        tree[v].max = arr[tl];
        tree[v].min = arr[tl];
    }
    else
    {
        int mid = (tr+tl)/2;
        build(arr, 2*v,tl, mid);
        build(arr, 2*v+1, mid+1, tr);
        tree[v] = combine(tree[2*v], tree[2*v+1]);
    }
}

int main()
{
    int n;
    // cin>>n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
        // cin>>arr[i];
    build(arr, 1, 0, n-1);
    int m;
    // cin>>m;
    scanf("%d", &m);
    
    while(m--)
    {
        int x;
        // cin>>x;
        scanf("%d",&x);
        // memset(marked, false, sizeof(marked));
        // if(tree[1] > x)
        // {
        for(int i=0;i<n;i++)
        {
            if(arr[i] > x)
                arr[i]--;
        }
        query(arr, 1, x, 0, n-1, 0);
            // marked[1] = true;
            // cout<<"marked 1"<<endl;
        // }
        // query(1, x, 0, n-1);
        // for(int i=1;i<=4*n;i++)
        // {
        //     cout<<marked[i]<<" ";
        // }
        // cout<<endl;
        
        // cout<<endl;
    }
    // pr(arr, 1, 0, n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<sub[i]<<" ";
    // }
    return 0;
}