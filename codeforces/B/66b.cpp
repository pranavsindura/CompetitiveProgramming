#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int maxcount = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int count = 1;
        int m = arr[i];
        for(int j = i - 1; j >= 0; j--)
        {
            if(arr[j] <= m)
                count++, m = arr[j];
            else
                break;
        }
        m = arr[i];
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] <= m)
                count++, m = arr[j];
            else
                break;
        }
        maxcount  = max(maxcount, count);
    }
    cout << maxcount;
    return 0;
}