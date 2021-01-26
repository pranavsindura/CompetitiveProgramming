#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int start = 0, end = n - 1, sum[2][1] = {0}, i = 0;
    while (start <= end)
    {
        if (arr[start] > arr[end])
        {
            sum[i][0] += arr[start];
            start++;
        }
        else
        {
            sum[i][0] += arr[end];
            end--;
        }
        i = (i+1)%2;
    }
    cout<<sum[0][0]<<" "<<sum[1][0];
    return 0;
}