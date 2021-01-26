#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    ll c = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i])
            c++;
    }
    if(c == 0)
    {
        cout << c;
        return 0;
    }
    c = 0;
    ll ans = 1;
    int j;
    for(int i = 0; i < n; i++)
    {
        if(arr[i])
        {
            j = i;
            break;
        }
    }
    for(int i = j; i < n; i++)
    {
        if(arr[i])
        {
            ans *= (c + 1);
            c = 0;
        }
        else
            c++;
    }
    cout << ans;
    return 0;
}