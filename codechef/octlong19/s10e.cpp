#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c = 1;
        cin >> n;
        int arr[n + 10];
        arr[0] = INT_MAX;
        arr[1] = INT_MAX;
        arr[2] = INT_MAX;
        arr[3] = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i+4];
        }
        // for (int i =0;i<(n+4);i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        for (int i = 5, j=0; i < (n+4); i++, j++)
        {
            if (arr[i] < arr[j] && arr[i] < arr[j+1] && arr[i] < arr[j+2] && arr[i] < arr[j+3] && arr[i] < arr[j+4])
            {
                // cout<<j<<endl;
                c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}