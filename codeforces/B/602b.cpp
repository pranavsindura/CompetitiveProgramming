#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    vector<int> diff(n);
    diff[0] = 0;
    for(int i = 1; i < n; i++)
    {
        diff[i] = arr[i] - arr[i - 1];
    }
    int j = 0, l = 0, ld = 0;
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(diff[i])
        {

            if(diff[i] == ld)
            {
                l = j;
            }
            j = i;
            ld = diff[i];
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
}