#include <bits/stdc++.h>
using namespace std;

int *st;
int findGcd(int ss, int se, int qs, int qe, int si)
{
    if (ss > qe || se < qs)
        return 0;
    if (qs <= ss && qe >= se)
        return st[si];
    int mid = ss + (se - ss) / 2;
    return __gcd(findGcd(ss, mid, qs, qe, si * 2 + 1),
                 findGcd(mid + 1, se, qs, qe, si * 2 + 2));
}

int gcd(int ss, int se, int arr[], int n)
{
    if (ss < 0 || se > n - 1 || ss > se)
    {
        return 0;
    }
    return findGcd(0, n - 1, ss, se, 0);
}

int constructST(int arr[], int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = ss + (se - ss) / 2;
    st[si] = __gcd(constructST(arr, ss, mid, si * 2 + 1),
                   constructST(arr, mid + 1, se, si * 2 + 2));
    return st[si];
}

int *constructSegmentTree(int arr[], int n)
{
    int height = (int)(ceil(log2(n)));
    int size = 2 * (int)pow(2, height) - 1;
    st = new int[size];
    constructST(arr, 0, n - 1, 0);
    return st;
}
int res[1000005];

int main()
{
    int n,q,k;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    constructSegmentTree(arr, n);
    // TLE
    for(int l=1;l<=1000;l++)
    {
        int c = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(l%gcd(i,j,arr,n) == 0)
                {
                    c++;
                }
            }
        }
        res[l] = c;
    }
    cin>>q;
    while(q--)
    {
        //index not position
        int k;
        cin>>k;
        cout<<res[k]<<endl;
    }
    return 0;
}