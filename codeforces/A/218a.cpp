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
    int n, m;
    cin >> n >> m;
    vector<int> arr(2 * n + 1);
    for(int i = 0; i < 2 * n + 1; i++)
        cin >> arr[i];
    int p = 1;
    for(int i=1;i<2*n && m;i+=2)
    {
        if(arr[i]-1 > arr[i+1] && arr[i]-1 > arr[i-1])
            arr[i]--, m--;
    }
    for(int x : arr)
        cout << x << " ";
    return 0;
}