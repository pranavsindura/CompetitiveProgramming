#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vpii vector<pii>
#define vll vector<ll>
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        ll arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        // sort(arr, arr + 3);
        // int a = arr[2] - arr[0];
        // int b = arr[1] - arr[0];
        ll x =  arr[0]+arr[1]+arr[2];
        // cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        if(2*arr[0] > x+1 || 2*arr[1] > x+1 || 2*arr[2] > x+1)
        {
                cout << "No\n";
        
        }
        else
        {
            cout << "Yes\n";
        }
    }
    return 0;
}