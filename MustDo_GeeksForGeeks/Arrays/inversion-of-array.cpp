/*
	Count inversions of array
	pairs such that
	a[i] > a[j] and i < j
*/

/*
	Approach 1 - Check every pair O(n^2)

	Approach 2 - Use Merge Sort O(nlogn)
	Merge sort's merge step gives us two sorted arrays left half and right half
	example -
	12345 134
	if L[i] > R[j]
	then all pairs -> (i,j) (i+1,j) (i+2,j) ... (n1-1,j) are inversions (count: n1-i)
	because left half elements are never moved over to the right hence what were inversions will remain inversions
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAXN 1000
vector<ll> arr(MAXN);

ll merge(int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<ll> L(n1), R(n2);
    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    ll inv_count = 0;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k] = L[i], i++;
        else
            arr[k] = R[j], j++, inv_count += n1 - i;
        k++;
    }
    while(i < n1)
        arr[k] = L[i], i++, k++;
    while(j < n2)
        arr[k] = R[j], j++, k++;
    return inv_count;
}

ll mergeSort(int l, int r)
{
    if(l >= r)
        return 0;
    int m = (l + r) / 2;
    ll left = mergeSort(l, m);
    ll right = mergeSort(m + 1, r);
    ll mid = merge(l, m, r);
    return left + right + mid;
}

int main()
{
    // FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        ll ans = mergeSort(0, n - 1);
        cout << ans << endl;
    }
    return 0;
}